#include "cart.h"
#include "pizza.h"
#include "drink.h"
#include "helpers.h"

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>

using namespace std;

// CartItem
CartItem::CartItem() : type(NoneType), name(""), quantity(0), price(0.0) {}
CartItem::CartItem(const Pizza& pizza, int quantity) { _assign(PizzaType, pizza.getName(), quantity, pizza.getPrice()); }
CartItem::CartItem(const Drink& drink, int quantity) { _assign(DrinkType, drink.getName(), quantity, drink.getPrice()); }

void CartItem::displayInfo() const {
    cout << left << setw(30) << name
        << "x " << right << setw(3) << quantity
        << "  @" << right << setw(9) << fixed << setprecision(2) << price << "  = "
        << right << setw(10) << fixed << setprecision(2) << getTotalPrice() << " UAH\n";
}
double CartItem::getTotalPrice() const { return quantity * price; }
string CartItem::getName() const { return name; }
int    CartItem::getQuantity() const { return quantity; }
double CartItem::getPrice() const { return price; }
typeOfProduct CartItem::getType() const { return type; }

void CartItem::setQuantity(int q) { if (q <= 0) throw invalid_argument("Quantity must be > 0"); quantity = q; }
void CartItem::increaseQuantity(int d) { if (d <= 0) throw invalid_argument("Increase delta must be > 0"); quantity += d; }
void CartItem::decreaseQuantity(int d) {
    if (d <= 0) throw invalid_argument("Decrease delta must be > 0");
    if (quantity - d < 0) throw logic_error("Quantity cannot go negative");
    quantity -= d;
}
void CartItem::_assign(typeOfProduct t, const string& n, int q, double p) {
    if (n.empty()) throw invalid_argument("Empty product name");
    if (q <= 0) throw invalid_argument("Quantity must be > 0");
    if (p < 0.0) throw invalid_argument("Price must be >= 0");
    type = t; name = n; quantity = q; price = p;
}

// Cart
void Cart::addItem(const CartItem& it) { items.push_back(it); }
void Cart::removeItem(int index) {
    if (index <= 0 || index > (int)items.size()) throw out_of_range("Cart item index out of range");
    items.erase(items.begin() + index - 1);
    cout << "Item #" << index << " removed.\n";
}
void Cart::clear() { items.clear(); }
double Cart::calculateTotal() const {
    double s = 0.0; for (size_t i = 0; i < items.size(); i++) s += items[i].getTotalPrice();
    return s;
}
void Cart::displayCart() const {
    if (items.empty()) { cout << "Cart is empty.\n"; return; }
    title("Your Cart");
    cout << left << setw(32) << "Name" << setw(6) << "Qty\t" << right << setw(14) << "Price" << setw(14) << "Sum" << "\n";
    hr();
    for (size_t i = 0; i < items.size(); i++) { cout << right << setw(2) << (i + 1) << ") "; items[i].displayInfo(); }
    hr();
    cout << right << setw(55) << "Total: " << right << setw(10) << fixed << setprecision(2) << calculateTotal() << " UAH\n";
    hr('=');
}
vector<CartItem> Cart::getItems() const { return items; }
bool Cart::isEmpty() const { return items.empty(); }
