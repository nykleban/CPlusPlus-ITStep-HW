#include <iostream>
#include <string>

using namespace std;

// 1: Washing Machine
struct WashingMachine {
    string brand;
    string color;
    double width;
    double length;
    double height;
    int power;
    int spinSpeed;
    int heatingTemperature;
};

void printWM(WashingMachine a) {
    cout << "\t=== Washing Machine ===\n";
    cout << "Brand: " << a.brand << endl;
    cout << "Color: " << a.color << endl;
    cout << "Width: " << a.width << " cm" << endl;
    cout << "Length: " << a.length << " cm" << endl;
    cout << "Height: " << a.height << " cm" << endl;
    cout << "Power: " << a.power << " W" << endl;
    cout << "Spin speed: " << a.spinSpeed << endl;
    cout << "Heating temperature: " << a.heatingTemperature << " C" << endl<<endl;
}

// 2: Iron
struct Iron {
    string brand;
    string model;
    string color;
    int minTemp;
    int maxTemp;
    bool steam;
    int power;
};

void printIron(Iron a) {
    cout << "\t=== Iron ===\n";
    cout << "Brand: " << a.brand << endl;
    cout << "Model: " << a.model << endl;
    cout << "Color: " << a.color << endl;
    cout << "Minimum temperature: " << a.minTemp << " C" << endl;
    cout << "Maximum temperature: " << a.maxTemp << " C" << endl;
    cout << "Steam function: " << (a.steam ? "Yes" : "No") << endl;
    cout << "Power: " << a.power << " W" << endl << endl;
}

// 3: Boiler
struct Boiler {
    string brand;
    string color;
    int power;
    int volume;
    int heatingTemperature;
};

void printBoiler(Boiler a) {
    cout << "\t=== Boiler ===\n";
    cout << "Brand: " << a.brand << endl;
    cout << "Color: " << a.color << endl;
    cout << "Power: " << a.power << " W" << endl;
    cout << "Volume: " << a.volume << " L" << endl;
    cout << "Heating temperature: " << a.heatingTemperature << " C" << endl << endl;
}



int main() {
    WashingMachine machine1 = { "Samsung", "White", 60.0, 55.0, 85.0, 2000, 1200, 90 };
    printWM(machine1);

    Iron iron1 = { "Philips", "GC5039", "Blue", 100, 220, true, 3000 };
    printIron(iron1);

    Boiler boiler1 = { "Ariston", "Silver", 1500, 80, 75 };
    printBoiler(boiler1);
}
