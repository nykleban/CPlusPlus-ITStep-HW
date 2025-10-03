#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// output horizontal lines
void hr(char ch = '-', int n = 74);
void title(const string& t);

// like explicit
// safe read for int and double
int readInt(const string& prompt = "");
double readDouble(const string& prompt = "");

// there are some code that was written by ChatGPT
// text helpers
vector<string> splitCSV(const string& s);
vector<string> splitBy(const string& s, char delim);

#endif
