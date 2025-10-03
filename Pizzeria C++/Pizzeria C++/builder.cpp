#include "builder.h"
#include "ingredient.h"

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

CustomPizzaBuilder::CustomPizzaBuilder(const IngredientStore* s) : store(s) {}

CustomPizzaBuilder& CustomPizzaBuilder::setName(const string& n) {
    if (n.empty()) throw invalid_argument("Custom pizza name empty");
    name = n; return *this;
}
CustomPizzaBuilder& CustomPizzaBuilder::setSize(int cm) {
    if (!_validSize(cm)) throw invalid_argument("Custom size must be 20/30/40");
    sizeCm = cm;
    if (cm == Small) sizeMultiplier = 0.9;
    else if (cm == Medium) sizeMultiplier = 1.0;
    else if (cm == Large) sizeMultiplier = 1.2;
    return *this;
}
CustomPizzaBuilder& CustomPizzaBuilder::addIngredientByName(const string& ingName) {
    if (!store) throw logic_error("IngredientStore is null");
    const Ingredient* ing = store->getByName(ingName);
    if (!ing) throw out_of_range("No such ingredient: " + ingName);
    if (!ing->isAvailable) throw runtime_error("Ingredient unavailable: " + ingName);
    chosenIngredients.push_back(ing->name);
    return *this;
}
CustomPizza CustomPizzaBuilder::build() const {
    if (!store) throw logic_error("IngredientStore is null");
    if (!_validSize(sizeCm)) throw invalid_argument("Custom size invalid");
    if (name.empty()) throw invalid_argument("Custom pizza name empty");
    double sum = 0.0;
    for (size_t i = 0; i < chosenIngredients.size(); i++) {
        const Ingredient* ing = store->getByName(chosenIngredients[i]);
        if (!ing) throw runtime_error("Ingredient missing during build: " + chosenIngredients[i]);
        sum += ing->price;
    }
    double price = basePrice * sizeMultiplier + sum;
    return CustomPizza(name, chosenIngredients, sizeCm, price);
}
