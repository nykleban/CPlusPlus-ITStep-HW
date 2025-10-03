#include "helpers.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

static string _trim(const string& x) {
    size_t a = 0, b = x.size();
    while (a < b && (x[a] == ' ' || x[a] == '\t')) ++a;
    while (b > a && (x[b - 1] == ' ' || x[b - 1] == '\t')) --b;
    return x.substr(a, b - a);
}

void hr(char ch, int n) {
    for (int i = 0; i < n; i++) cout << ch;
    cout << "\n";
}
void title(const string& t) {
    cout << "\n";
    hr('=');
    cout << " " << t << "\n";
    hr('=');
}

int readInt(const string& prompt) {
    if (!prompt.empty()) cout << prompt;
    string s; getline(cin, s);
    if (s.empty()) return 0;
    try { return stoi(s); }
    catch (...) { return 0; }
}
double readDouble(const string& prompt) {
    if (!prompt.empty()) cout << prompt;
    string s; getline(cin, s);
    if (s.empty()) return 0.0;
    try { return stod(s); }
    catch (...) { return 0.0; }
}

vector<string> splitCSV(const string& s) {
    vector<string> out; string cur;
    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == ',' || c == ';') { string v = _trim(cur); if (!v.empty()) out.push_back(v); cur.clear(); }
        else cur.push_back(c);
    }
    string v = _trim(cur); if (!v.empty()) out.push_back(v);
    return out;
}

vector<string> splitBy(const string& s, char delim) {
    vector<string> parts; string cur;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == delim) { parts.push_back(cur); cur.clear(); }
        else cur.push_back(s[i]);
    }
    parts.push_back(cur);
    return parts;
}
