using namespace std;
#include <iostream>

void drawPatternA(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j <= i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void drawPatternB(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j >= i) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void drawPatternC(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j >= size - i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void drawPatternD(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j <= size - i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int size;
    cout << "Enter the number of rows: ";
    cin >> size;
    drawPatternA(size);
    cout << endl;
    drawPatternB(size);
    cout << endl;
    drawPatternC(size);
    cout << endl;
    drawPatternD(size);

    return 0;
}