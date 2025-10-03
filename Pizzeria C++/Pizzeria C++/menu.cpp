#include "menu.h"
#include "ingredient.h"
#include "helpers.h"

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

static bool pizzaHasAll(const Pizza& P, const vector<string>& need) {
    vector<string> ing = P.getIngredients();
    for (size_t k = 0; k < need.size(); ++k) {
        bool has = false;
        for (size_t j = 0; j < ing.size(); ++j) if (ing[j] == need[k]) { has = true; break; }
        if (!has) return false;
    }
    return true;
}
static bool pizzaHasAny(const Pizza& P, const vector<string>& need) {
    vector<string> ing = P.getIngredients();
    for (size_t k = 0; k < need.size(); ++k)
        for (size_t j = 0; j < ing.size(); ++j) if (ing[j] == need[k]) return true;
    return false;
}

void Menu::addPizza(const Pizza& p) { pizzas.push_back(p); }
void Menu::addDrink(const Drink& d) { drinks.push_back(d); }

void Menu::removePizza(int index) {
    if (index <= 0 || index > (int)pizzas.size()) throw out_of_range("Pizza index out of range");
    pizzas.erase(pizzas.begin() + index - 1);
    cout << "Pizza #" << index << " removed.\n";
}
void Menu::removeDrink(int index) {
    if (index <= 0 || index > (int)drinks.size()) throw out_of_range("Drink index out of range");
    drinks.erase(drinks.begin() + index - 1);
    cout << "Drink #" << index << " removed.\n";
}

int Menu::findPizzaByName(const string& n) const { for (int i = 0; i < (int)pizzas.size(); i++) if (pizzas[i].getName() == n) return i; return -1; }
int Menu::findDrinkByName(const string& n) const { for (int i = 0; i < (int)drinks.size(); i++) if (drinks[i].getName() == n) return i; return -1; }

void Menu::findPizzaByIngredient(const string& ingredient) const {
    title(string("Search pizzas by ingredient: ") + ingredient);
    int found = 0;
    for (size_t i = 0; i < pizzas.size(); i++) {
        const vector<string>& ing = pizzas[i].getIngredients();
        bool has = false;
        for (size_t j = 0; j < ing.size(); ++j) if (ing[j] == ingredient) { has = true; break; }
        if (has) pizzas[i].displayRowWithLine(++found);
    }
    if (found == 0) cout << "Not found.\n";
}
void Menu::findPizzasByMulti(const vector<string>& keys, bool allMode) const {
    title(allMode ? "Search (ALL ingredients)" : "Search (ANY ingredient)");
    int found = 0;
    for (size_t i = 0; i < pizzas.size(); i++) {
        bool ok = allMode ? pizzaHasAll(pizzas[i], keys) : pizzaHasAny(pizzas[i], keys);
        if (ok) pizzas[i].displayRowWithLine((int)++found);
    }
    if (found == 0) cout << "Not found.\n";
}

void Menu::displayPizzas() const {
    title("PIZZA MENU");
    if (pizzas.empty()) { cout << "(No pizzas)\n"; return; }
    cout << left << setw(4) << "No" << setw(26) << "Name" << setw(10) << "Size" << setw(10) << "" << right << setw(12) << "Price" << "\n";
    hr();
    for (size_t i = 0; i < pizzas.size(); i++) pizzas[i].displayRowWithLine((int)i + 1);
}
void Menu::displayDrinks() const {
    title("DRINKS MENU");
    if (drinks.empty()) { cout << "(No drinks)\n"; return; }
    for (size_t i = 0; i < drinks.size(); i++) {
        cout << right << setw(2) << (i + 1) << ". ";
        drinks[i].displayInfo();
    }
    hr('=');
}
void Menu::displayMenu() const { displayPizzas(); displayDrinks(); }

vector<Pizza> Menu::getPizzas() const { return pizzas; }
vector<Drink> Menu::getDrinks() const { return drinks; }

bool Menu::saveToFile(const string& path, const string& pzName, const string& pzAddr, const IngredientStore& store) const {
    ofstream f(path.c_str(), ios::out | ios::trunc);
    if (!f.is_open()) throw ios_base::failure("Cannot open file for write: " + path);
    f.exceptions(std::ios::badbit | std::ios::failbit);

    f << "PIZZERIA|" << pzName << "|" << pzAddr << "\n";
    vector<Ingredient> all = store.list();
    for (size_t i = 0; i < all.size(); i++) {
        f << "ING|" << all[i].id << "|" << all[i].name << "|" << all[i].price << "|" << all[i].stockQty << "|" << (all[i].isAvailable ? 1 : 0) << "\n";
    }
    for (size_t i = 0; i < drinks.size(); i++) {
        f << "DR|" << drinks[i].getName() << "|" << drinks[i].getVolume() << "|" << drinks[i].getPrice() << "\n";
    }
    for (size_t i = 0; i < pizzas.size(); i++) {
        f << "PZ|" << pizzas[i].getName() << "|" << pizzas[i].getSize() << "|" << pizzas[i].getPrice() << "|";
        vector<string> ing = pizzas[i].getIngredients();
        for (size_t j = 0; j < ing.size(); ++j) { f << ing[j]; if (j + 1 < ing.size()) f << ","; }
        f << "\n";
    }
    return true;
}

vector<string> Menu::splitByLocal(const string& s, char delim) { return ::splitBy(s, delim); }

bool Menu::loadFromFile(const string& path, string& pzName, string& pzAddr, IngredientStore& store) {
    ifstream f(path.c_str());
    if (!f.is_open()) throw ios_base::failure("Cannot open file: " + path);

    pizzas.clear(); drinks.clear(); store.clear();

    string line; int ln = 0;
    while (getline(f, line)) {
        ++ln; if (line.size() < 3) continue;
        vector<string> parts = splitByLocal(line, '|');
        if (parts.empty()) continue;

        if (parts[0] == "PIZZERIA") {
            if (parts.size() < 3) throw runtime_error("Bad PIZZERIA line " + to_string(ln));
            pzName = parts[1]; pzAddr = parts[2];
        }
        else if (parts[0] == "ING") {
            if (parts.size() < 6) throw runtime_error("Bad ING line " + to_string(ln));
            double price = stod(parts[3]); int stock = stoi(parts[4]); int avail = stoi(parts[5]);
            store.add(parts[2], price, stock, (avail != 0));
        }
        else if (parts[0] == "DR") {
            if (parts.size() < 4) throw runtime_error("Bad DR line " + to_string(ln));
            double vol = stod(parts[2]); double pr = stod(parts[3]);
            drinks.push_back(Drink(parts[1], vol, pr));
        }
        else if (parts[0] == "PZ") {
            if (parts.size() < 5) throw runtime_error("Bad PZ line " + to_string(ln));
            int size = stoi(parts[2]); double pr = stod(parts[3]);
            vector<string> ings = splitCSV(parts[4]);
            pizzas.push_back(Pizza(parts[1], ings, size, pr));
        }
        else {
            throw runtime_error("Unknown record '" + parts[0] + "' at line " + to_string(ln));
        }
    }
    return true;
}
