#ifndef CART_H
#define CART_H

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

class Pizza;
class Drink;

enum typeOfProduct { NoneType = 0, PizzaType, DrinkType };

class CartItem {
private:
    typeOfProduct type;
    string name;
    int quantity;
    double price;
public:
    CartItem();
    CartItem(const Pizza& pizza, int quantity);
    CartItem(const Drink& drink, int quantity);

    void displayInfo() const;
    double getTotalPrice() const;
    string getName() const;
    int    getQuantity() const;
    double getPrice() const;
    typeOfProduct getType() const;

    void setQuantity(int q);
    void increaseQuantity(int d = 1);
    void decreaseQuantity(int d = 1);
    void _assign(typeOfProduct t, const string& n, int q, double p);
};

class Cart {
private:
    vector<CartItem> items;
public:
    void addItem(const CartItem& it);
    void removeItem(int index);
    void clear();
    double calculateTotal() const;
    void displayCart() const;
    vector<CartItem> getItems() const;
    bool isEmpty() const;
};

#endif 
