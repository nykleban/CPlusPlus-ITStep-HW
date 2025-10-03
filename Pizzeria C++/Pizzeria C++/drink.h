#ifndef DRINK_H
#define DRINK_H

#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

class Drink {
    string name;
    double volumeInLiters;
    double price;
public:
    Drink();
    Drink(string n, double v, double p);
    void displayInfo() const;

    string getName() const;
    double getPrice() const;
    double getVolume() const;

    void setName(const string& n);
    void setPrice(double p);
    void setVolume(double v);
};

#endif
