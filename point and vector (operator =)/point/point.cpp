#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
	Point p1(3, 4);
	Point p2(5, 12);
	p1.Print();
	p2.Print();
	--p1; // Pre-decrement
	p1.Print();
	--p2; // Pre-decrement
	p2.Print();
	++p1; // Pre-increment
	p1.Print();
	++p2; // Pre-increment
	p2.Print();
	!p1; // Negate p1
	p1.Print();
	!p2; // Negate p2
	p2.Print();
	p1 > p2 ? cout << "p1 is farther from (0, 0) than p2\n" : cout << "p1 is closer from (0, 0) than p2\n";
	Vector vector;
	vector.Add(p1);
	vector.Add(p2);
	vector.Print();
	Point p3(1, 2);
	vector.Add(p3);
	vector.Print();

}
