#include "drink.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

Drink::Drink() : name(""), volumeInLiters(0.0), price(0.0) {}
Drink::Drink(string n, double v, double p) : name(n), volumeInLiters(v), price(p) {
    if (name.empty()) throw invalid_argument("Drink name is empty");
    if (volumeInLiters <= 0.0) throw invalid_argument("Drink volume must be > 0");
    if (price < 0.0) throw invalid_argument("Drink price must be >= 0");
}
void Drink::displayInfo() const {
    cout << left << setw(28) << name
        << "Volume: " << setw(3) << volumeInLiters << " L\tPrice: " << right << setw(9) << fixed << setprecision(2) << price << " UAH\n";
}
string Drink::getName() const { return name; }
double Drink::getPrice() const { return price; }
double Drink::getVolume() const { return volumeInLiters; }

void Drink::setName(const string& n) { if (n.empty()) throw invalid_argument("Drink name is empty"); name = n; }
void Drink::setPrice(double p) { if (p < 0.0) throw invalid_argument("Price must be >= 0"); price = p; }
void Drink::setVolume(double v) { if (v <= 0.0) throw invalid_argument("Volume must be > 0"); volumeInLiters = v; }
