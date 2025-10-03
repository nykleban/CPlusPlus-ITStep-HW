#ifndef PIZZERIA_H
#define PIZZERIA_H

#include <string>
#include <vector>

using namespace std;

#include "user.h"
#include "menu.h"
#include "ingredient.h"
#include "cart.h"

class Pizzeria {
private:
    string name;
    string address;
    Menu menu;
    IngredientStore store;
    vector<User> users;
    vector<Admin> admins;
    vector<Cart> carts;

public:
    Pizzeria();
    Pizzeria(const string& n, const string& a);

    string getName() const;
    string getAddress() const;
    void setName(const string& n);
    void setAddress(const string& a);

    Menu& getMenu();
    const Menu& getMenu() const;

    IngredientStore& getStore();
    const IngredientStore& getStore() const;

    void showMenu() const;
    void addUser(const User& u);
    void addAdmin(const Admin& a);

    int newCart();
    bool validcartNumber(int cartNumber) const;

    double checkoutCart(int cartNumber, const string& cashier, const string& paymentMethod, double delivery = 0.0, double discount = 0.0);

    bool saveAll(const string& path);
    bool loadAll(const string& path);

    // ADMIN MENU FUNCTIONS
    void addPizza();
    void deletePizza();
    void addDrink();
    void deleteDrink();
    void searchPizzaByOneIngredient() const;
    void viewStore() const;
    void addIngredient();
    void editIngredient();
    void deleteIngredient();
    void save();
    void load();
    void multiIngredientSearch(bool all) const;
    void editPizza();

    // USER MENU FUNCTIONS
    void viewMenu() const;
    void addPizzaToCart(int cartNumber);
    void addDrinkToCart(int cartNumber);
    void showCart(int cartNumber) const;
    void removeCartItem(int cartNumber);
    void removeOnlyPizza(int cartNumber);
    void removeOnlyDrink(int cartNumber);
    void searchPizzaByOneIngredient_User() const;
    void buildCustomPizza(int cartNumber);
    void multiIngredientSearch_User(bool all) const;
    void checkout(int cartNumber);
};

#endif
