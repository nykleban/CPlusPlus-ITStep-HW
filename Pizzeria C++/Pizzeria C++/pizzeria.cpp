#include "pizzeria.h"
#include "builder.h"
#include "helpers.h"

#include <fstream>
#include <ctime>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

Pizzeria::Pizzeria() : name(""), address(""), menu(), store(), users{}, admins{}, carts{} {}
Pizzeria::Pizzeria(const string& n, const string& a) : name(n), address(a), menu(), store(), users{}, admins{}, carts{} {}

string Pizzeria::getName() const { return name; }
string Pizzeria::getAddress() const { return address; }
void Pizzeria::setName(const string& n) { name = n; }
void Pizzeria::setAddress(const string& a) { address = a; }

Menu& Pizzeria::getMenu() { return menu; }
const Menu& Pizzeria::getMenu() const { return menu; }
IngredientStore& Pizzeria::getStore() { return store; }
const IngredientStore& Pizzeria::getStore() const { return store; }

void Pizzeria::showMenu() const { menu.displayMenu(); }
void Pizzeria::addUser(const User& u) { users.push_back(u); }
void Pizzeria::addAdmin(const Admin& a) { admins.push_back(a); }

int Pizzeria::newCart() { carts.push_back(Cart{}); return (int)carts.size(); }
bool Pizzeria::validcartNumber(int cartNumber) const { return cartNumber > 0 && cartNumber <= (int)carts.size(); }

double Pizzeria::checkoutCart(int cartNumber, const string& cashier, const string& paymentMethod, double delivery, double discount) {
    if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
    if (delivery < 0.0) throw invalid_argument("Delivery cannot be negative");
    if (discount < 0.0) throw invalid_argument("Discount cannot be negative");

    double subtotal = carts[cartNumber - 1].calculateTotal();
    if (subtotal <= 0.0) throw logic_error("Cart is empty");
    double total = subtotal - discount + delivery;
    if (total < 0.0) throw logic_error("Total cannot be negative");

    // time written by ChatGPT for local time printing
    time_t tt = time(nullptr);
    tm tmv{};
#ifdef _WIN32
    localtime_s(&tmv, &tt);
#else
    localtime_r(&tt, &tmv);
#endif

    title("RECEIPT");
    cout << "Pizzeria: " << name << "\nAddress: " << address
        << "\nCashier: " << cashier << "\nPayment: " << paymentMethod
        << "\nDate/Time: " << put_time(&tmv, "%d.%m.%Y %H:%M") << "\n";
    hr();
    cout << left << setw(32) << "Item" << setw(6) << "Qty" << right << setw(14) << "Price" << right << setw(14) << "Sum" << "\n";
    hr();
    vector<CartItem> its = carts[cartNumber - 1].getItems();
    for (size_t i = 0; i < its.size(); i++) its[i].displayInfo();
    hr();
    cout << right << setw(56) << "Subtotal: " << right << setw(10) << fixed << setprecision(2) << subtotal << " UAH\n";
    if (discount > 0)  cout << right << setw(56) << "Discount: " << right << setw(10) << discount << " UAH\n";
    if (delivery > 0)  cout << right << setw(56) << "Delivery: " << right << setw(10) << delivery << " UAH\n";
    hr();
    cout << right << setw(56) << "Total Due: " << right << setw(10) << total << " UAH\n";
    hr('=');

    ofstream f("receipt_last.txt", ios::out | ios::trunc);
    if (!f.is_open()) throw ios_base::failure("Cannot open receipt file");
    f.exceptions(std::ios::badbit | std::ios::failbit);

    f << "=== " << name << " ===\n";
    f << "Address: " << address << "\n";
    f << "Cashier: " << cashier << "\n";
    f << "Payment: " << paymentMethod << "\n";
    char dts[64];
    strftime(dts, sizeof(dts), "%d.%m.%Y %H:%M", &tmv);
    f << "Date/Time: " << dts << "\n";
    for (size_t i = 0; i < its.size(); i++) {
        f << (i + 1) << ") " << its[i].getName() << " x" << its[i].getQuantity()
            << " @" << fixed << setprecision(2) << its[i].getPrice()
            << " = " << fixed << setprecision(2) << its[i].getTotalPrice() << " UAH\n";
    }
    f << "Subtotal: " << subtotal << " UAH\n";
    if (discount > 0) f << "Discount: " << discount << " UAH\n";
    if (delivery > 0) f << "Delivery: " << delivery << " UAH\n";
    f << "Total Due: " << total << " UAH\n";
    f << "Thank you!\n";

    carts[cartNumber - 1].clear();
    return total;
}

bool Pizzeria::saveAll(const string& path) { return menu.saveToFile(path, name, address, store); }
bool Pizzeria::loadAll(const string& path) {
    string n = name, a = address;
    bool ok = menu.loadFromFile(path, n, a, store);
    if (ok) { name = n; address = a; }
    return ok;
}

// ADMIN
void Pizzeria::addPizza() {
    cout << "Pizza name: ";
    string nm; getline(cin, nm);
    int size = readInt("Size (20/30/40): ");
    double price = readDouble("Price: ");
    int k = readInt("Ingredients count: ");
    vector<string> ing;
    for (int i = 0; i < k; ++i) {
        cout << "  Ingredient #" << (i + 1) << ": ";
        string s; getline(cin, s);
        if (!s.empty()) ing.push_back(s);
    }
    menu.addPizza(Pizza(nm, ing, size, price));
    cout << "Pizza added.\n";
}
void Pizzeria::deletePizza() { menu.displayPizzas(); int index = readInt("Pizza number to delete: "); menu.removePizza(index); }
void Pizzeria::addDrink() {
    cout << "Drink name: ";
    string n; getline(cin, n);
    double v = readDouble("Volume (L): ");
    double p = readDouble("Price: ");
    menu.addDrink(Drink(n, v, p));
    cout << "Drink added.\n";
}
void Pizzeria::deleteDrink() { menu.displayDrinks(); int index = readInt("Drink number to delete: "); menu.removeDrink(index); }
void Pizzeria::searchPizzaByOneIngredient() const { cout << "Ingredient: "; string q; getline(cin, q); menu.findPizzaByIngredient(q); }
void Pizzeria::viewStore() const { store.display(); }
void Pizzeria::addIngredient() {
    cout << "Ingredient name: "; string n; getline(cin, n);
    double pr = readDouble("Price (UAH): ");
    int st = readInt("Stock (pcs): ");
    int av = readInt("Available? (1/0): ");
    store.add(n, pr, st, av != 0);
    cout << "Ingredient added.\n";
}
void Pizzeria::editIngredient() {
    store.display();
    int id = readInt("Ingredient ID: ");
    cout << "New name: "; string n; getline(cin, n);
    double pr = readDouble("New price: ");
    int st = readInt("New stock: ");
    int av = readInt("Available? (1/0): ");
    if (store.edit(id, n, pr, st, av != 0)) cout << "Updated.\n";
}
void Pizzeria::deleteIngredient() { store.display(); int id = readInt("Ingredient ID to delete: "); if (store.remove(id)) cout << "Deleted.\n"; }
void Pizzeria::save() { cout << "File path (e.g., db.txt): "; string p; getline(cin, p); if (saveAll(p)) cout << "Saved.\n"; }
void Pizzeria::load() { cout << "File path: "; string p; getline(cin, p); if (loadAll(p)) cout << "Loaded.\n"; }
void Pizzeria::multiIngredientSearch(bool all) const { cout << "Enter ingredients separated by commas: "; string line; getline(cin, line); vector<string> keys = splitCSV(line); menu.findPizzasByMulti(keys, all); }

void Pizzeria::editPizza() {
    vector<Pizza> P = menu.getPizzas();
    menu.displayPizzas();
    int index = readInt("Pizza number to EDIT: ");
    if (index <= 0 || index > (int)P.size()) throw out_of_range("Invalid pizza index");
    Pizza old = P[index - 1];

    cout << "New name (blank=keep '" << old.getName() << "'): ";
    string nm; getline(cin, nm);
    if (nm.empty()) nm = old.getName();

    int sz = readInt("New size (20/30/40, 0=keep): ");
    if (sz == 0) sz = old.getSize();

    double pr = readDouble("New price (-1=keep): ");
    if (pr < 0) pr = old.getPrice();

    vector<string> newIng = old.getIngredients();
    cout << "Change ingredients? (y/n): ";
    string yn; getline(cin, yn);
    if (!yn.empty() && (yn[0] == 'y' || yn[0] == 'Y')) {
        newIng.clear();
        cout << "Enter ingredients separated by commas: ";
        string line; getline(cin, line);
        newIng = splitCSV(line);
    }

    menu.removePizza(index);
    menu.addPizza(Pizza(nm, newIng, sz, pr));
    cout << "Pizza edited.\n";
}

// USER
void Pizzeria::viewMenu() const { showMenu(); }
void Pizzeria::addPizzaToCart(int cartNumber) {
    if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
    menu.displayPizzas();
    int index = readInt("Pizza number: ");
    int qty = readInt("Quantity: ");
    const vector<Pizza> P = menu.getPizzas();
    if (index <= 0 || index > (int)P.size()) throw out_of_range("Pizza number invalid");
    carts[cartNumber - 1].addItem(CartItem(P[index - 1], qty));
    cout << "Added.\n";
}
void Pizzeria::addDrinkToCart(int cartNumber) {
    if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
    menu.displayDrinks();
    int index = readInt("Drink number: ");
    int qty = readInt("Quantity: ");
    const vector<Drink> D = menu.getDrinks();
    if (index <= 0 || index > (int)D.size()) throw out_of_range("Drink number invalid");
    carts[cartNumber - 1].addItem(CartItem(D[index - 1], qty));
    cout << "Added.\n";
}
void Pizzeria::showCart(int cartNumber) const { if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid"); carts[cartNumber - 1].displayCart(); }
void Pizzeria::removeCartItem(int cartNumber) {
    if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
    carts[cartNumber - 1].displayCart();
    int index = readInt("Item number: ");
    carts[cartNumber - 1].removeItem(index);
}
void Pizzeria::removeOnlyPizza(int cartNumber) {
    if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
    if (carts[cartNumber - 1].isEmpty()) { cout << "Cart is empty. Nothing to remove.\n"; return; }
    vector<CartItem> items = carts[cartNumber - 1].getItems();
    bool found = false;
    for (size_t i = 0; i < items.size(); ++i) if (items[i].getType() == PizzaType) { cout << (i + 1) << ") " << items[i].getName() << " x" << items[i].getQuantity() << "\n"; found = true; }
    if (!found) { cout << "No pizzas in cart.\n"; return; }
    int index = readInt("Enter pizza item number to remove: ");
    if (index <= 0 || index > (int)items.size() || items[index - 1].getType() != PizzaType) throw out_of_range("Invalid pizza item number");
    carts[cartNumber - 1].removeItem(index);
}
void Pizzeria::removeOnlyDrink(int cartNumber) {
    if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
    if (carts[cartNumber - 1].isEmpty()) { cout << "Cart is empty. Nothing to remove.\n"; return; }
    vector<CartItem> items = carts[cartNumber - 1].getItems();
    bool found = false;
    for (size_t i = 0; i < items.size(); ++i) if (items[i].getType() == DrinkType) { cout << (i + 1) << ") " << items[i].getName() << " x" << items[i].getQuantity() << "\n"; found = true; }
    if (!found) { cout << "No drinks in cart.\n"; return; }
    int index = readInt("Enter drink item number to remove: ");
    if (index <= 0 || index > (int)items.size() || items[index - 1].getType() != DrinkType) throw out_of_range("Invalid drink item number");
    carts[cartNumber - 1].removeItem(index);
}
void Pizzeria::searchPizzaByOneIngredient_User() const { cout << "Ingredient: "; string q; getline(cin, q); menu.findPizzaByIngredient(q); }
void Pizzeria::buildCustomPizza(int cartNumber) {
    if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
    const IngredientStore& st = store;
    st.display();
    CustomPizzaBuilder b(&st);
    cout << "Custom pizza name: "; string nm; getline(cin, nm); b.setName(nm);
    int sz = readInt("Size (20/30/40): "); b.setSize(sz);
    cout << "Enter ingredients separated by commas: "; string line; getline(cin, line);
    vector<string> keys = splitCSV(line);
    for (size_t i = 0; i < keys.size(); i++) b.addIngredientByName(keys[i]);
    CustomPizza cp = b.build();
    cout << "\nYour pizza:\n"; cp.displayInfo();
    int qty = readInt("How many to add to cart?: ");
    carts[cartNumber - 1].addItem(CartItem(cp, qty));
    cout << "Added to cart.\n";
}
void Pizzeria::multiIngredientSearch_User(bool all) const { cout << "Enter ingredients separated by commas: "; string line; getline(cin, line); vector<string> keys = splitCSV(line); menu.findPizzasByMulti(keys, all); }
void Pizzeria::checkout(int cartNumber) {
    if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
    double delivery = readDouble("Delivery (0 - pickup): ");
    double discount = readDouble("Discount (0 - none): ");
    string cashier = "Vasia";
    string pay;
    while (true) {
        cout << "Payment type (cash/card): ";
        getline(cin, pay);
        if (pay == "cash" || pay == "card") break;
        else cout << "Payment must be 'cash' or 'card'. Try again.\n";
    }
    double total = checkoutCart(cartNumber, cashier, pay, delivery, discount);
    cout << "Payment accepted. Total: " << fixed << setprecision(2) << total << " UAH\n";
}
