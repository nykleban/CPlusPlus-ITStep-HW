#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

struct Ingredient {
    int id{ 0 };
    string name;
    double price{ 0.0 };
    int stockQty{ 0 };
    bool isAvailable{ true };
};

class IngredientStore {
    vector<Ingredient> items;
    int nextId = 1;
public:
    int add(const string& name, double price, int stock = 0, bool avail = true);
    bool remove(int id);
    bool edit(int id, const string& nm, double pr, int stock, bool avail);
    const Ingredient* getById(int id) const;
    const Ingredient* getByName(const string& nm) const;
    vector<Ingredient> list() const;
    void clear();
    void display() const;
};

#endif
