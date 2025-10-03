#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

enum sizeOfPizza { none = 0, Small = 20, Medium = 30, Large = 40 };

class Pizza {
private:
    string name;
    vector<string> ingredients;
    int sizeInCm;
    double price;
    static bool _validSize(int s);
public:
    Pizza();
    Pizza(string n, vector<string> ingr, int size, double p);
    virtual ~Pizza() = default;

    virtual void displayInfo() const;
    void displayRowWithLine(int index) const;

    string getName() const;
    int    getSize() const;
    double getPrice() const;
    vector<string> getIngredients() const;

    void setName(const string& n);
    void setSize(int s);
    void setPrice(double p);
    void addIngredient(const string& i);
    void clearIngredients();
    void changeIngredient(const string& oldI, const string& newI);
};

class CustomPizza : public Pizza {
public:
    CustomPizza();
    CustomPizza(string n, vector<string> ing, int s, double p);
    void setCustomName(const string& n);
    void displayInfo() const override;
};

#endif 
