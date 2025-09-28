// tetris.cpp — компактний і стабільний консольний Tetris (C++17, один файл)
// Фічі: 10x20 поле, 7-bag, прості wall-kick, soft/hard drop, рахунок і рівні,
// кросплатформенний неблокуючий ввід (Windows/Unix), ANSI-рендер.
//
// Перевірено на: g++/clang++, MSVC.
// Автор надає у публічне надбання (CC0). Користуйтесь вільно!

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <random>
#include <chrono>
#include <thread>
#include <cstring>
#include <cstdint>
#include <algorithm>

using namespace std;

// ===================== Платформо-залежний неблокуючий ввід ===================
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
bool kb_hit() { return _kbhit(); }
int  kb_get() { return _getch(); }
void sleep_ms(int ms) { Sleep(ms); }
void enable_raw_mode() {} // не потрібно
void disable_raw_mode() {}
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
static termios orig_termios{};
void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags & ~O_NONBLOCK);
}
void enable_raw_mode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    termios raw = orig_termios;
    cfmakeraw(&raw);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    atexit(disable_raw_mode);
}
bool kb_hit() {
    unsigned char ch;
    ssize_t n = read(STDIN_FILENO, &ch, 1);
    if (n == 1) { ungetc(ch, stdin); return true; }
    return false;
}
int kb_get() {
    int c = getchar();
    return (c == EOF) ? -1 : c;
}
void sleep_ms(int ms) { usleep(ms * 1000); }
#endif

// ============================= ANSI утиліти ==================================
const string CSI = "\x1b[";
void cls() { cout << CSI << "2J" << CSI << "H"; }
void hideCursor() { cout << CSI << "?25l"; }
void showCursor() { cout << CSI << "?25h"; }
void moveTo(int r, int c) { cout << CSI << r << ";" << c << "H"; }
const string RESET = "\x1b[0m";
string bg(int idx) { // 0..6
    static const char* codes[] = {
        "\x1b[44m", // L -> синій
        "\x1b[46m", // I -> бірюзовий
        "\x1b[43m", // O -> жовтий
        "\x1b[45m", // T -> пурпур
        "\x1b[42m", // S -> зелений
        "\x1b[41m", // Z -> червоний
        "\x1b[44;1m"// J -> яскраво-синій
    };
    return codes[idx % 7];
}
const string DIM = "\x1b[90m";

// =============================== Константи ===================================
static const int W = 10;
static const int H = 20;     // видима висота
static const int HBUF = 22;  // з буфером зверху для спавну

// =============================== Тетроміно ===================================
struct Tet {
    // базова маска 4x4 (спавн), потім генеруємо 3 оберти CW
    uint16_t spawnMask;
    int color; // 0..6
    char name;
};

uint16_t maskFromRows(const array<string, 4>& rows) {
    // Кожен рядок рівно 4 символи '.' або '#'
    uint16_t m = 0;
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            if (rows[r][c] == '#') m |= (1u << (r * 4 + c));
    return m;
}
uint16_t rotCW(uint16_t m) {
    // обертання 4x4 CW: (r,c)->(c,3-r)
    uint16_t r = 0;
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            if (m & (1u << (y * 4 + x))) {
                int nx = 3 - y;
                int ny = x;
                r |= (1u << (ny * 4 + nx));
            }
    return r;
}
array<uint16_t, 4> allRots(uint16_t spawn) {
    array<uint16_t, 4> a{};
    a[0] = spawn; a[1] = rotCW(a[0]); a[2] = rotCW(a[1]); a[3] = rotCW(a[2]);
    return a;
}

vector<Tet> makeTets() {
    vector<Tet> t(7);
    // I
    t[0] = Tet{ maskFromRows({ "....","####","....","...." }), 1, 'I' };
    // O
    t[1] = Tet{ maskFromRows({ ".##.",".##.","....","...." }), 2, 'O' };
    // T
    t[2] = Tet{ maskFromRows({ ".#..","###.","....","...." }), 3, 'T' };
    // S
    t[3] = Tet{ maskFromRows({ ".##.","##..","....","...." }), 4, 'S' };
    // Z
    t[4] = Tet{ maskFromRows({ "##..",".##.","....","...." }), 5, 'Z' };
    // J
    t[5] = Tet{ maskFromRows({ "#...","###.","....","...." }), 6, 'J' };
    // L
    t[6] = Tet{ maskFromRows({ "..#.","###.","....","...." }), 0, 'L' };
    return t;
}

// ================================ Ігрові типи ================================
struct Piece {
    int id;     // 0..6
    int rot;    // 0..3
    int x, y;    // позиція лівого-верхнього кута маски 4x4
};

struct Board {
    array<array<int, W>, HBUF> g{};
    Board() { for (auto& r : g) r.fill(-1); }
    bool in(int x, int y) const { return x >= 0 && x < W && y >= 0 && y < HBUF; }
    bool empty(int x, int y) const { return in(x, y) && g[y][x] == -1; }
};

// прості wall-kicks: пробуємо dx у {0,-1,1,-2,2} при обертанні
const int KICKS[] = { 0,-1,1,-2,2 };

// ================================ Гра ========================================
struct Game {
    Board b;
    vector<Tet> T;
    array<array<uint16_t, 4>, 7> R; // усі оберти для кожного тетроміно
    mt19937 rng;
    deque<int> bag;
    Piece cur{};
    long long score = 0;
    int lines = 0, level = 1;
    bool over = false, paused = false;

    Game() :T(makeTets()), rng((uint32_t)chrono::high_resolution_clock::now().time_since_epoch().count()) {
        for (int i = 0; i < 7; i++) R[i] = allRots(T[i].spawnMask);
        refillBag();
        spawn();
    }

    void refillBag() {
        vector<int> v = { 0,1,2,3,4,5,6 };
        shuffle(v.begin(), v.end(), rng);
        for (int x : v) bag.push_back(x);
    }
    int draw() {
        if (bag.empty()) refillBag();
        int v = bag.front(); bag.pop_front();
        if (bag.size() < 7) refillBag();
        return v;
    }

    bool collides(const Piece& p) const {
        uint16_t m = R[p.id][p.rot];
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                if (m & (1u << (r * 4 + c))) {
                    int x = p.x + c, y = p.y + r;
                    if (x < 0 || x >= W || y >= HBUF) return true;
                    if (y >= 0 && b.g[y][x] != -1) return true;
                }
            }
        }
        return false;
    }

    void place(const Piece& p) {
        uint16_t m = R[p.id][p.rot];
        for (int r = 0; r < 4; r++)
            for (int c = 0; c < 4; c++)
                if (m & (1u << (r * 4 + c))) {
                    int x = p.x + c, y = p.y + r;
                    if (y >= 0 && y < HBUF) b.g[y][x] = T[p.id].color;
                }
    }

    int clearLines() {
        int cleared = 0;
        for (int y = 0; y < H; y++) {
            bool full = true;
            for (int x = 0; x < W; x++) if (b.g[y][x] == -1) { full = false; break; }
            if (full) {
                cleared++;
                for (int yy = y; yy > 0; --yy) b.g[yy] = b.g[yy - 1];
                b.g[0].fill(-1);
            }
        }
        return cleared;
    }

    void updateScore(int cleared, int softDrop, int hardDrop) {
        static const int base[5] = { 0,100,300,500,800 };
        score += base[cleared] * level;
        score += softDrop;         // 1 за клітинку soft-drop
        score += hardDrop * 2;       // 2 за клітинку hard-drop
        lines += cleared;
        level = 1 + lines / 10;
    }

    int gravityMs() const {
        // проста крива швидкості: від 800мс до 90мс
        int base = 800 - (level - 1) * 60;
        return max(90, base);
    }

    void spawn() {
        cur = Piece{ draw(), 0, 3, -2 };
        if (collides(cur)) over = true;
    }

    bool moveXY(int dx, int dy) {
        Piece t = cur; t.x += dx; t.y += dy;
        if (!collides(t)) { cur = t; return true; }
        return false;
    }

    bool rotateCW() {
        int newRot = (cur.rot + 1) & 3;
        for (int dx : KICKS) {
            Piece t = cur; t.rot = newRot; t.x += dx;
            if (!collides(t)) { cur = t; return true; }
        }
        return false;
    }

    void hardDrop() {
        int cells = 0;
        while (moveXY(0, 1)) cells++;
        place(cur);
        int cleared = clearLines();
        updateScore(cleared, /*soft*/0, /*hard*/cells);
        spawn();
    }

    // Рендер поля, стани ліворуч/праворуч, підказки керування
    void render() {
        int top = 2, left = 4;
        moveTo(1, 1);
        cout << "TETRIS  "
            << "Score: " << score << "  Lines: " << lines
            << "  Level: " << level << (paused ? "  [PAUSE]" : "            ") << "\n";

        // рамка
        for (int y = 0; y < H; y++) {
            moveTo(top + y, left - 1); cout << DIM << "|" << RESET;
            moveTo(top + y, left + W * 2); cout << DIM << "|" << RESET;
        }
        moveTo(top + H, left - 1); cout << DIM << "+" << string(W * 2, '-') << "+" << RESET;

        // фон
        for (int y = 0; y < H; y++) {
            moveTo(top + y, left);
            for (int x = 0; x < W; x++) {
                int v = b.g[y][x];
                if (v == -1) cout << "  ";
                else cout << bg(v) << "  " << RESET;
            }
        }

        // поточна фігура
        uint16_t m = R[cur.id][cur.rot];
        for (int r = 0; r < 4; r++)
            for (int c = 0; c < 4; c++)
                if (m & (1u << (r * 4 + c))) {
                    int x = cur.x + c, y = cur.y + r;
                    if (y >= 0 && y < H) {
                        moveTo(top + y, left + x * 2);
                        cout << bg(T[cur.id].color) << "  " << RESET;
                    }
                }

        // підказки
        moveTo(top, left + W * 2 + 3);
        cout << "Controls:";
        moveTo(top + 1, left + W * 2 + 3); cout << "A/D: move";
        moveTo(top + 2, left + W * 2 + 3); cout << "W: rotate";
        moveTo(top + 3, left + W * 2 + 3); cout << "S: soft drop";
        moveTo(top + 4, left + W * 2 + 3); cout << "Space: hard drop";
        moveTo(top + 5, left + W * 2 + 3); cout << "P: pause, Q: quit";

        cout.flush();
    }
};

// ================================ main =======================================
int main() {
#ifndef _WIN32
    enable_raw_mode();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    hideCursor();
    cls();

    Game G;

    auto lastFall = chrono::high_resolution_clock::now();
    auto lastRender = lastFall;
    int softDropCells = 0;

    // простий цикл гри ~60 FPS
    while (!G.over) {
        // ---- input ----
        while (kb_hit()) {
            int ch = kb_get();
            if (ch == -1) break;

#ifdef _WIN32
            // Для Windows: ігноруємо спецкоди стрілок, працюємо з WASD/Space.
            if (ch == 0 || ch == 224) { (void)kb_get(); continue; }
#endif
            // Нормалізуємо до верхнього регістру
            if (ch >= 'a' && ch <= 'z') ch = ch - 'a' + 'A';

            if (ch == 'A') { G.moveXY(-1, 0); }
            else if (ch == 'D') { G.moveXY(1, 0); }
            else if (ch == 'S') {
                if (G.moveXY(0, 1)) { G.score += 1; softDropCells++; }
            }
            else if (ch == 'W') { G.rotateCW(); }
            else if (ch == ' ') { G.hardDrop(); softDropCells = 0; }
            else if (ch == 'P') { G.paused = !G.paused; }
            else if (ch == 'Q') { G.over = true; }
        }

        // ---- gravity ----
        auto now = chrono::high_resolution_clock::now();
        auto ms = [&](auto t) { return chrono::duration_cast<chrono::milliseconds>(now - t).count(); };

        if (!G.paused && ms(lastFall) >= G.gravityMs()) {
            if (!G.moveXY(0, 1)) {
                // Лочимо фігуру
                G.place(G.cur);
                int cleared = G.clearLines();
                G.updateScore(cleared, softDropCells, 0);
                softDropCells = 0;
                G.spawn();
            }
            lastFall = now;
        }

        // ---- render (60 FPS) ----
        if (ms(lastRender) >= 16) {
            G.render();
            lastRender = now;
        }

        // невелика пауза
        sleep_ms(1);
    }

    cls(); showCursor();
#ifndef _WIN32
    disable_raw_mode();
#endif
    cout << "\nGame Over!\nScore: " << G.score
        << "  Lines: " << G.lines
        << "  Level: " << G.level << "\n";
    return 0;
}
