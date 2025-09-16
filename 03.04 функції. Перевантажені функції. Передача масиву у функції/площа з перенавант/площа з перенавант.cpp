#include <iostream>
using namespace std;
#include <cmath>

float sTriangle(int a, int h) {
	if (a <= 0 || h <= 0) {
		return 0;
	}
    else
    {
        return (a * h) / 2;
    }
}

float sTriangle(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c<=0) {
        return 0;
    }
	else if (a + b <= c || a + c <= b || b + c <= a) {
		return 0;
	}
    else
    {
		float p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
}

int main() {
    int a, b;
    cout << "Enter 2 numbers(storona and height): ";
    cin >> a >> b;
    cout << "Square of triangle = " << sTriangle(a, b) << endl;

    int c;
    cout << "Enter 3 storony: ";
    cin >> a >> b >> c;
    cout << "Square of triangle = " << sTriangle(a, b, c) << endl;

    return 0;
}
