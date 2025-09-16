#include <iostream>
#include <string> //це щоб використовувати "to_string"
#include <fstream>
using namespace std;

class Point {
private:
    double x;
    double y;
    double z;
public:
	void inputPoint() {
		cout << "Enter coordinates (x y z): ";
		cin >> x >> y >> z;
	}
	void inputPoint(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void printPoint() {
		cout << "Point coordinates: (" << x << ", " << y << ", " << z << ")" << endl;
	}
	double whatIsX() {
		return x;
	}
	double whatIsY() {
		return y;
	}
	double whatIsZ() {
		return z;
	}
};

    void saveCoordinatesToFile(Point& point, const string& filename) {
		ofstream outFile(filename);
		if (outFile.is_open()) {
			outFile << "Coordinates: (" << point.whatIsX() << ", "
				<< point.whatIsY() << ", " << point.whatIsZ() << ")" << endl;
			outFile.close();
			cout << "Coordinates saved to " << filename << endl;
		}
		else {
			cout << "Unable to open file for writing." << endl;
		}
    }
	void loadCoordinatesFromFile(Point& point, const string& filename) {
		ifstream inFile(filename);
		if (inFile.is_open()) {
			string line;
			getline(inFile, line);
			double x, y, z;

			// Формат має бути: Coordinates: (1.1, 2.2, 3.3)
			if (sscanf_s(line.c_str(), "Coordinates: (%lf, %lf, %lf)", &x, &y, &z) == 3) { // sscanf — розбір тексту по шаблону
				point.inputPoint(x, y, z);
				cout << "Coordinates loaded from " << filename << endl;
				point.printPoint();
			}
			else {
				cout << "Invalid file format." << endl;
			}

			inFile.close();
		}
		else {
			cout << "Unable to open file for reading." << endl;
		}
	}
int main() {
	Point point;
	const string FILENAME = "coordinates.txt";
	point.inputPoint();
	point.printPoint();
	saveCoordinatesToFile(point, FILENAME);
	Point loadedPoint;
	loadCoordinatesFromFile(loadedPoint, FILENAME);
}
