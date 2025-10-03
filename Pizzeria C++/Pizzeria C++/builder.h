#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include <vector>

using namespace std;

#include "pizza.h"

class IngredientStore;

class CustomPizzaBuilder {
    string name = "Your Recipe";
    vector<string> chosenIngredients;
    int sizeCm = Medium;
    double basePrice = 60.0;
    double sizeMultiplier = 1.0;
    const IngredientStore* store{ nullptr };
    static bool _validSize(int s) { return s == Small || s == Medium || s == Large; }
public:
    CustomPizzaBuilder(const IngredientStore* s);
    CustomPizzaBuilder& setName(const string& n);
    CustomPizzaBuilder& setSize(int cm);
    CustomPizzaBuilder& addIngredientByName(const string& ingName);
    CustomPizza build() const;
};

#endif 
