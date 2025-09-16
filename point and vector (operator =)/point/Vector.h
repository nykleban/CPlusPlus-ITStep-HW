#pragma once
#include "Point.h"

class Vector
{
private:
    Point* points;
    int countPoint;
public:
	Vector() : points(nullptr), countPoint(0) {}
	Vector(const Vector& other) : countPoint(other.countPoint) {
		this->points = new Point[this->countPoint];
		for (int i = 0; i < this->countPoint; i++) {
			this->points[i] = other.points[i];
		}
	}
	~Vector() {
		delete[] this->points;
	}
	Vector& operator=(const Vector& other) {
		if (this != &other) {
			delete[] this->points;
			this->countPoint = other.countPoint;
			this->points = new Point[this->countPoint];
			for (int i = 0; i < this->countPoint; i++) {
				this->points[i] = other.points[i];
			}
		}
		return *this;
	}
	void Add(const Point& point) {
		Point* newPoints = new Point[this->countPoint + 1];
		for (int i = 0; i < this->countPoint; i++) {
			newPoints[i] = this->points[i];
		}
		newPoints[this->countPoint] = point;
		delete[] this->points;
		this->points = newPoints;
		this->countPoint++;
	}
	void Print() const {
		cout << "----------------------------------\n";
		cout << "Vector of Points:\n";
		for (int i = 0; i < this->countPoint; i++) {
			this->points[i].Print();
		}
		if (this->countPoint == 0) {
			cout << "No points in the vector.\n";
		}
		cout << "----------------------------------\n";
	}
};
