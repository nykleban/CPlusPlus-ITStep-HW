#include <iostream>
using namespace std;
#include <string>

class Airplane
{
private:
string model;
string type;
int passengers;
int maxCapacity;
public:
Airplane(string m, string t, int p, int mC) :model(m), type(t), passengers(p), maxCapacity(mC) {};

friend bool operator ==(Airplane& a1, Airplane& a2);
friend bool operator >(Airplane& a1, Airplane& a2);

void operator ++(int) 
{
	if (passengers < maxCapacity)
	{
		passengers++;
		cout << "++ Passengers in "<<this->model<<": " << passengers << endl;
	}
	else
	{
		cout << "Capacity is full!" << endl;
	}
};
void operator --(int) 
{
	if (passengers > 0)
	{
		passengers--;
		cout << "-- Passengers in " << this->model << ": " << passengers << endl;
	}
	else
	{
		cout << "No passengers to remove!" << endl;
	}
};

void operator() (int n)
{
	if (passengers+n <= maxCapacity)
	{
		passengers += n;
		cout << "+n Passengers in " << this->model << ": " << passengers << endl;
	}
	else
	{
		cout << "Capacity is full! Cannot add "<<n<< "." << endl;
	}
};

void displayInfo() const
{
	cout << "Model: " << model << ", Type: " << type
		<< ", Passengers: " << passengers
		<< ", Max Capacity: " << maxCapacity << endl;
}

operator string() const
{
	return model;
}

// Fix: Define the ostream operator<< as a friend function
friend ostream& operator<<(ostream& os, const Airplane& airplane)
{
	os << "Model: " << airplane.model << ", Type: " << airplane.type
		<< ", Passengers: " << airplane.passengers
		<< ", Max Capacity: " << airplane.maxCapacity;
	return os;
}

friend istream& operator>>(istream& is, Airplane& airplane)
{
	cout << "Enter model: ";
	is >> airplane.model;
	cout << "Enter type: ";
	is >> airplane.type;
	cout << "Enter passengers: ";
	is >> airplane.passengers;
	cout << "Enter max capacity: ";
	is >> airplane.maxCapacity;
	return is;
}
};

bool operator ==(Airplane& a1, Airplane& a2)
{
if (a1.type == a2.type)
{return true;}
else
{return false;}
}

bool operator >(Airplane& a1, Airplane& a2)
{
if (a1.maxCapacity > a2.maxCapacity)
{
	return true;
}
else
{
	return false;
}
}

int main()
{
Airplane a1("Boeing 747", "Commercial", 150, 400);
a1.displayInfo(); 
Airplane a2("Airbus A380", "Commercial", 200, 600);
a2.displayInfo(); 
cout << "Comparing airplanes by type: " << (a1 == a2 ? "Equal" : "Not Equal") << endl;
cout << "Comparing airplanes by capacity: " << (a1 > a2 ? "A1 has more capacity" : "A2 has more capacity") << endl;
a1++; // Increment passengers
a1--; // Decrement passengers
a1(50); // Add 50 passengers;
a1.displayInfo(); // Display updated info
cout << "Using string conversion: " << string(a1) << endl; // Convert to string
cout << "Using ostream operator: ";
cout << a1 << endl; // Use ostream operator
cout << "Using istream operator: ";
cin >> a1; // Use istream operator
a1.displayInfo();
}
