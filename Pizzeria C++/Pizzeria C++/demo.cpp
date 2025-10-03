#include "demo.h"
#include "pizzeria.h"
#include "pizza.h"
#include "drink.h"
#include "ingredient.h"

#include <string>
#include <vector>

using namespace std;

void setupDemoMenuAndStock(Pizzeria& pizzeria) {
    pizzeria.getMenu().addPizza(Pizza("Margherita", { "Mozzarella", "Tomato", "Basil" }, Medium, 129.0));
    pizzeria.getMenu().addPizza(Pizza("Pepperoni", { "Mozzarella", "Pepperoni" }, Large, 179.0));
    pizzeria.getMenu().addPizza(Pizza("Funghi", { "Mozzarella", "Mushrooms", "Tomato" }, Small, 99.0));
    pizzeria.getMenu().addPizza(Pizza("Hawaiian", { "Mozzarella", "Ham", "Pineapple" }, Medium, 145.0));
    pizzeria.getMenu().addPizza(Pizza("Quattro Formaggi", { "Mozzarella", "Gorgonzola", "Parmesan", "Ricotta" }, Large, 189.0));
    pizzeria.getMenu().addPizza(Pizza("Vegetariana", { "Mozzarella", "Tomato", "Bell Pepper", "Olives", "Onion" }, Small, 109.0));
    pizzeria.getMenu().addDrink(Drink("Cola", 0.5, 39.0));
    pizzeria.getMenu().addDrink(Drink("Orange juice", 0.33, 42.0));
    pizzeria.getMenu().addDrink(Drink("Mineral water", 0.5, 25.0));
    pizzeria.getMenu().addDrink(Drink("Beer", 0.5, 55.0));
    pizzeria.getMenu().addDrink(Drink("Wine", 0.75, 199.0));
    pizzeria.getMenu().addDrink(Drink("Lemonade", 0.33, 45.0));
    pizzeria.getStore().add("Mozzarella", 20.0, 50, true);
    pizzeria.getStore().add("Tomato", 8.0, 100, true);
    pizzeria.getStore().add("Basil", 6.0, 40, true);
    pizzeria.getStore().add("Pepperoni", 25.0, 30, true);
    pizzeria.getStore().add("Mushrooms", 12.0, 60, true);
    pizzeria.getStore().add("Ham", 22.0, 25, true);
    pizzeria.getStore().add("Pineapple", 15.0, 20, true);
    pizzeria.getStore().add("Gorgonzola", 30.0, 15, true);
    pizzeria.getStore().add("Parmesan", 28.0, 15, true);
    pizzeria.getStore().add("Ricotta", 26.0, 15, true);
    pizzeria.getStore().add("Bell Pepper", 10.0, 50, true);
    pizzeria.getStore().add("Olives", 14.0, 50, true);
    pizzeria.getStore().add("Onion", 7.0, 80, true);
    pizzeria.getStore().add("Chicken", 24.0, 30, true);
    pizzeria.getStore().add("Salami", 27.0, 30, true);
}
void loadDBTXT(Pizzeria& pizzeria, string path) {
    try {
        if (pizzeria.loadAll(path)) {
            cout << "Database loaded from " << path << "\n";
        }
    }
    catch (const exception& e) {
        cerr << "Load error: " << e.what() << "\n";
    }
    setupDemoMenuAndStock(pizzeria);
}