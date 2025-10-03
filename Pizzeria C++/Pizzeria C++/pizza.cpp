#include "pizza.h"
#include "helpers.h"

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

bool Pizza::_validSize(int s) { return s == Small || s == Medium || s == Large; }

Pizza::Pizza() : name(""), ingredients{}, sizeInCm(none), price(0.0) {}
Pizza::Pizza(string n, vector<string> ingr, int size, double p)
    : name(n), ingredients(ingr), sizeInCm(size), price(p) {
    if (name.empty()) throw invalid_argument("Pizza name is empty");
    if (!_validSize(size)) throw invalid_argument("Pizza size must be 20/30/40");
    if (price < 0.0) throw invalid_argument("Pizza price must be >= 0");
}

void Pizza::displayInfo() const {
    cout << left << setw(28) << name
        << "Size: " << setw(3) << sizeInCm << " cm\tPrice: " << right << setw(9) << fixed << setprecision(2) << price << " UAH\n";
    cout << "    " << left << setw(14) << "Ingredients: ";
    for (size_t i = 0; i < ingredients.size(); i++) {
        cout << ingredients[i];
        if (i + 1 < ingredients.size()) cout << ", ";
    }
    cout << "\n";
}
void Pizza::displayRowWithLine(int index) const {
    cout << right << setw(2) << index << ". ";
    displayInfo();
    hr();
}

string Pizza::getName() const { return name; }
int    Pizza::getSize() const { return sizeInCm; }
double Pizza::getPrice() const { return price; }
vector<string> Pizza::getIngredients() const { return ingredients; }

void Pizza::setName(const string& n) {
    if (n.empty()) throw invalid_argument("Pizza name is empty");
    name = n;
}
void Pizza::setSize(int s) {
    if (!_validSize(s)) throw invalid_argument("Pizza size must be 20/30/40");
    sizeInCm = s;
}
void Pizza::setPrice(double p) {
    if (p < 0.0) throw invalid_argument("Price must be >= 0");
    price = p;
}
void Pizza::addIngredient(const string& i) {
    if (i.empty()) throw invalid_argument("Ingredient name is empty");
    ingredients.push_back(i);
}
void Pizza::clearIngredients() { ingredients.clear(); }
void Pizza::changeIngredient(const string& oldI, const string& newI) {
    if (newI.empty()) throw invalid_argument("New ingredient name is empty");
    for (size_t i = 0; i < ingredients.size(); i++)
        if (ingredients[i] == oldI) { ingredients[i] = newI; return; }
    throw out_of_range("Ingredient to change not found: " + oldI);
}

CustomPizza::CustomPizza() : Pizza() {}
CustomPizza::CustomPizza(string n, vector<string> ing, int s, double p) : Pizza(n, ing, s, p) {}
void CustomPizza::setCustomName(const string& n) { setName(n); }
void CustomPizza::displayInfo() const { cout << "(Custom) "; Pizza::displayInfo(); }
