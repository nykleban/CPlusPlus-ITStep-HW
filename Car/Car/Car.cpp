using namespace std;
#include <iostream>

class Engine
{
private:
		int horsepower;
public:
	Engine(): horsepower(1) {}
	Engine(int hp) : horsepower(hp) {}
	int getHorsepower() const { return horsepower; }
	void PrintEngine() const {
		cout << "Engine horsepower: " << horsepower << endl;
	}
};

enum DoorType
{
	DoorNone, VerticalOpen, HorizontalOpen
};
class Door
{
private:
	DoorType type;
public:
    Door() : type(DoorType::DoorNone) {};
	Door(DoorType t) : type(t) {};
	string getType() const {
		switch (type) {
		case DoorNone:
			return "No door";
			break;
		case VerticalOpen:
			return "Vertical opening door";
			break;
		case HorizontalOpen:
			return "Horizontal opening door";
			break;
		}
	}
	void PrintDoor() const {
		cout << "Door type: " << getType() << endl;
	}
};

enum ColorHeadlight
{
	ColorNone, White, Yellow
};
class Headlight
{
private:
	ColorHeadlight color;
public:
	Headlight() :color(ColorHeadlight::ColorNone) {};
	Headlight(ColorHeadlight c) : color(c) {};
	string getColor() const {
		switch (color) {
		case ColorNone:
			return "No headlight";
			break;
		case White:
			return "White";
			break;
		case Yellow:
			return "Yellow";
			break;
		}
	}
	void PrintHeadlight() const {
		cout << "Headlight color: " << getColor() << endl;
	}
};

class Wheel {
private:
		int size;
public:
	Wheel() : size(1) {};
	Wheel(int s) : size(s) {};
	int getSize() const { return size; }
	void PrintWheel() const {
		cout << "Wheel size: " << size << endl;
	}
};

enum MaterialBody
{
	MaterialNone, aluminum, steel, carbon
};
class Body {
private:
	MaterialBody material;
public:
	Body() : material(MaterialBody::MaterialNone) {};
	Body(MaterialBody m) : material(m) {};
	string getMaterial() const {
		switch (material) {
		case MaterialNone:
			return "No body";
			break;
		case aluminum:
			return "Aluminum";
			break;
		case steel:
			return "Steel";
			break;
		case carbon:
			return "Carbon";
			break;
		}
	}
	void PrintBody() const {
		cout << "Body material: " << getMaterial() << endl;
	}
};

class Driver {
	private:
	string name;
	string surname;
	int age;
	int StazhKeruvania; // 	стаж керування ТЗ (транспортний засіб) в роках
public:
	Driver(): name("No name"), age(0) {}
	Driver(string n,string sn, int a, int sk ) : name(n), age(a), surname(sn), StazhKeruvania(sk) {}
	void PrintDriver() const {
		cout << "Driver: " << name << " "<< surname << ", Age: " << age << ", Stazh keruvania: " << StazhKeruvania << endl;
	}
	
};

class Car {
private:
	string model;
	Engine engine;
	Door door;
	Headlight headlight;
	Wheel wheel;
	Body body;
	Driver* driver; 
public:
	Car() : model("No model"), engine(), door(), headlight(), wheel(), body(), driver(nullptr) {}
    Car(string m, Engine e, Door d, Headlight h, Wheel w, Body b, Driver &dr) 
		: model(m), engine(e), door(d), headlight(h), wheel(w), body(b), driver(&dr) {}
	void AddDriver(Driver& driver1) {
		if (driver != nullptr) driver = &driver1;
		else cout << "Driver already assigned" << endl;
	}
	void DeleteDriver() {
		if (driver != nullptr) driver = nullptr;
		else cout << "No driver to delete" << endl;
	}
	void PrintCar() const {
		cout << "----- Car Info -----" << endl;
		cout << "Car model: " << model << endl;
		engine.PrintEngine();
		door.PrintDoor();
		headlight.PrintHeadlight();
		wheel.PrintWheel();
		body.PrintBody();
		if (driver != nullptr) driver->PrintDriver();
		else cout << "No driver assigned" << endl;
	}
};


int main()
{
	Car car1;
	car1.PrintCar();
	Engine engine1(150);
	Door door1(DoorType::HorizontalOpen);
	Headlight headlight1(ColorHeadlight::White);
	Wheel wheel1(16);
	Body body1(MaterialBody::steel);
	Driver driver1("John", "Sino", 30, 12);
	Car car2("Toyota", engine1, door1, headlight1, wheel1, body1, driver1);
	car2.PrintCar();
	
	Driver driver2("Nazar", "Kleban", 18, 1);
	//а тепер зробимо машину мрії)
    Car car3("Audi RS8", Engine(630), Door(DoorType::VerticalOpen), Headlight(ColorHeadlight::White), Wheel(21), Body(MaterialBody::carbon), driver2);
	car3.PrintCar();
}
