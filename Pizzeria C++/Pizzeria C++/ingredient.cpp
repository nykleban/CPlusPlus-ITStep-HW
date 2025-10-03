#include "ingredient.h"
#include "helpers.h"

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

int IngredientStore::add(const string& name, double price, int stock, bool avail) {
    if (name.empty()) throw invalid_argument("Ingredient name empty");
    if (price < 0.0)  throw invalid_argument("Ingredient price < 0");
    if (stock < 0)    throw invalid_argument("Ingredient stock < 0");

    const Ingredient* ex = getByName(name);
    if (ex) {
        // якщо вже є — просто оновлюємо значення і повертаємо існуючий id
        edit(ex->id, name, price, stock, avail);
        return ex->id;
    }

    Ingredient ing;
    ing.id = nextId++;
    ing.name = name;
    ing.price = price;
    ing.stockQty = stock;
    ing.isAvailable = avail;
    items.push_back(ing);
    return ing.id;
}

bool IngredientStore::remove(int id) {
    for (size_t i = 0; i < items.size(); i++) if (items[i].id == id) { items.erase(items.begin() + i); return true; }
    throw out_of_range("Ingredient ID not found");
}
bool IngredientStore::edit(int id, const string& nm, double pr, int stock, bool avail) {
    if (nm.empty()) throw invalid_argument("Ingredient name empty");
    if (pr < 0.0)   throw invalid_argument("Ingredient price < 0");
    if (stock < 0)  throw invalid_argument("Ingredient stock < 0");
    for (size_t i = 0; i < items.size(); i++) if (items[i].id == id) {
        items[i].name = nm; items[i].price = pr; items[i].stockQty = stock; items[i].isAvailable = avail; return true;
    }
    throw out_of_range("Ingredient ID not found");
}
const Ingredient* IngredientStore::getById(int id) const { for (size_t i = 0; i < items.size(); i++) if (items[i].id == id) return &items[i]; return nullptr; }
const Ingredient* IngredientStore::getByName(const string& nm) const { for (size_t i = 0; i < items.size(); i++) if (items[i].name == nm) return &items[i]; return nullptr; }
vector<Ingredient> IngredientStore::list() const { return items; }
void IngredientStore::clear() { items.clear(); nextId = 1; }

void IngredientStore::display() const {
    title("INGREDIENT STOCK");
    if (items.empty()) { cout << "(Empty)\n"; return; }
    cout << left << setw(5) << "ID" << setw(28) << "Name" << right << setw(12) << "Price, UAH"
        << right << setw(10) << "Stock" << right << setw(10) << "Avail" << "\n";
    hr();
    for (size_t i = 0; i < items.size(); i++) {
        cout << left << setw(5) << items[i].id
            << setw(28) << items[i].name
            << right << setw(12) << fixed << setprecision(2) << items[i].price
            << right << setw(10) << items[i].stockQty
            << right << setw(10) << (items[i].isAvailable ? "yes" : "no") << "\n";
    }
    hr('=');
}
