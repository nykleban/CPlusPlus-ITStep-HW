#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

using namespace std;

#include "pizza.h"
#include "drink.h"

class IngredientStore;

class Menu {
private:
    vector<Pizza> pizzas;
    vector<Drink> drinks;
public:
    void addPizza(const Pizza& p);
    void addDrink(const Drink& d);

    void removePizza(int index);
    void removeDrink(int index);

    int findPizzaByName(const string& n) const;
    int findDrinkByName(const string& n) const;

    void findPizzaByIngredient(const string& ingredient) const;
    void findPizzasByMulti(const vector<string>& keys, bool allMode) const;

    void displayPizzas() const;
    void displayDrinks() const;
    void displayMenu() const;

    vector<Pizza> getPizzas() const;
    vector<Drink> getDrinks() const;

    // save/load to/from file(split written by ChatGPT for comfort in using)
    bool saveToFile(const string& path, const string& pzName, const string& pzAddr, const IngredientStore& store) const;
    static vector<string> splitByLocal(const string& s, char delim);
    bool loadFromFile(const string& path, string& pzName, string& pzAddr, IngredientStore& store);
};

#endif 
