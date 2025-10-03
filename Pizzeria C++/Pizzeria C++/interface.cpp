#include "interface.h"
#include "pizzeria.h"
#include "helpers.h"

#include <iostream>
#include <ios>
#include <string>
using namespace std;

void adminMenu(Pizzeria& pz) {
    while (true) {
        title("ADMIN MENU");
        cout << " 1) View menu\n"
            << " 2) Add pizza\n"
            << " 3) Delete pizza\n"
            << " 4) Add drink\n"
            << " 5) Delete drink\n"
            << " 6) Search pizzas by ingredient\n"
            << " 7) View ingredient stock\n"
            << " 8) Add ingredient\n"
            << " 9) Edit ingredient\n"
            << "10) Delete ingredient\n"
            << "11) Save database to file\n"
            << "12) Load database from file\n"
            << "13) Multi-ingredient search (ALL)\n"
            << "14) Multi-ingredient search (ANY)\n"
            << "15) Edit pizza (name/size/price/ingredients)\n"
            << "16) SWITCH TO USER\n"
            << " 0) Exit admin menu\n> ";

        int c = readInt();
        if (c == 0) break;

        try {
            if (c == 1) pz.showMenu();
            else if (c == 2) pz.addPizza();
            else if (c == 3) pz.deletePizza();
            else if (c == 4) pz.addDrink();
            else if (c == 5) pz.deleteDrink();
            else if (c == 6) pz.searchPizzaByOneIngredient();
            else if (c == 7) pz.viewStore();
            else if (c == 8) pz.addIngredient();
            else if (c == 9) pz.editIngredient();
            else if (c == 10) pz.deleteIngredient();
            else if (c == 11) pz.save();
            else if (c == 12) pz.load();
            else if (c == 13) pz.multiIngredientSearch(true);
            else if (c == 14) pz.multiIngredientSearch(false);
            else if (c == 15) pz.editPizza();
            else if (c == 16) userMenu(pz);
            else cout << "Unknown choice.\n";
        }
        catch (const ios_base::failure& e) { cout << "I/O error: " << e.what() << "\n"; }
        catch (const out_of_range& e) { cout << "Out of range: " << e.what() << "\n"; }
        catch (const invalid_argument& e) { cout << "Invalid argument: " << e.what() << "\n"; }
        catch (const logic_error& e) { cout << "Logic error: " << e.what() << "\n"; }
        catch (const exception& e) { cout << "Error: " << e.what() << "\n"; }
    }
}

void userMenu(Pizzeria& pz) {
    int cartNumber = pz.newCart();

    while (true) {
        title("USER MENU");
        cout << " 1) View menu\n"
            << " 2) Add pizza to cart\n"
            << " 3) Add drink to cart\n"
            << " 4) Show cart\n"
            << " 5) Remove cart item\n"
            << " 6) Checkout (payment)\n"
            << " 7) Search pizzas by ingredient\n"
            << " 8) Build your own pizza (from stock)\n"
            << " 9) Search pizzas ALL (multi-ingredient)\n"
            << "10) Search pizzas ANY (multi-ingredient)\n"
            << "11) Remove pizza from cart\n"
            << "12) Remove drink from cart\n"
            << " 0) Exit\n> ";

        int c = readInt();
        if (c == 0) break;

        try {
            if (c == 1) pz.viewMenu();
            else if (c == 2) pz.addPizzaToCart(cartNumber);
            else if (c == 3) pz.addDrinkToCart(cartNumber);
            else if (c == 4) pz.showCart(cartNumber);
            else if (c == 5) pz.removeCartItem(cartNumber);
            else if (c == 6) pz.checkout(cartNumber);
            else if (c == 7) pz.searchPizzaByOneIngredient_User();
            else if (c == 8) pz.buildCustomPizza(cartNumber);
            else if (c == 9) pz.multiIngredientSearch_User(true);
            else if (c == 10) pz.multiIngredientSearch_User(false);
            else if (c == 11) pz.removeOnlyPizza(cartNumber);
            else if (c == 12) pz.removeOnlyDrink(cartNumber);
            else cout << "Unknown choice.\n";
        }
        catch (const ios_base::failure& e) { cout << "I/O error: " << e.what() << "\n"; }
        catch (const out_of_range& e) { cout << "Out of range: " << e.what() << "\n"; }
        catch (const invalid_argument& e) { cout << "Invalid argument: " << e.what() << "\n"; }
        catch (const logic_error& e) { cout << "Logic error: " << e.what() << "\n"; }
        catch (const exception& e) { cout << "Error: " << e.what() << "\n"; }
    }
}
