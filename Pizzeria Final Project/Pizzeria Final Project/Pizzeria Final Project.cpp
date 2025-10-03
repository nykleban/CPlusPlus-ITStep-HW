#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <stdexcept>
#include <limits>
#include <cctype>

using namespace std;

// output horizontal lines
void hr(char ch = '-', int n = 74) {
    for (int i = 0; i < n; i++) cout << ch;
    cout << "\n";
}
void title(const string& t) {
    cout << "\n";
    hr('=');
    cout << " " << t << "\n";
    hr('=');
}

// like explicit
int readInt(const string& prompt = "") {
    if (!prompt.empty()) cout << prompt;
    string s;
    getline(cin, s);
    if (s.empty()) return 0;
    try {
        return stoi(s);
    }
    catch (...) {
        return 0;
    }
}
double readDouble(const string& prompt = "") {
    if (!prompt.empty()) cout << prompt;
    string s;
    getline(cin, s);
    if (s.empty()) return 0.0;
    try {
        return stod(s);
    }
    catch (...) {
        return 0.0;
    }
}

// classes
class User {
protected:
    string username;
    string password;
    bool isAdmin;
public:
    User() : username(""), password(""), isAdmin(false) {}
    User(string u, string p, bool admin = false) : username(u), password(p), isAdmin(admin) {}
    string getUsername() const {
        return username;
    }
    string getPassword() const {
        return password;
    }
    bool getIsAdmin() const {
        return isAdmin;
    }
    void setUsername(const string& u) {
        username = u;
    }
    void setPassword(const string& p) {
        password = p;
    }
};
class Admin : public User {
public:
    Admin() : User("", "", true) {}
    Admin(string u, string p) : User(u, p, true) {}
};


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
    CartItem() : type(NoneType), name(""), quantity(0), price(0.0) {}
    CartItem(const Pizza& pizza, int quantity);
    CartItem(const Drink& drink, int quantity);

    void displayInfo() const {
        cout << left << setw(30) << name
            << "x " << right << setw(3) << quantity
            << "  @" << right << setw(9) << fixed << setprecision(2) << price << "  = "
            << right << setw(10) << fixed << setprecision(2) << getTotalPrice() << " UAH\n";
    }
    double getTotalPrice() const {
        return quantity * price;
    }
    string getName() const {
        return name;
    }
    int    getQuantity() const {
        return quantity;
    }
    double getPrice() const {
        return price;
    }
    typeOfProduct getType() const {
        return type;
    }

    void setQuantity(int q) {
        if (q <= 0) throw invalid_argument("Quantity must be > 0");
        quantity = q;
    }
    void increaseQuantity(int d = 1) {
        if (d <= 0) throw invalid_argument("Increase delta must be > 0");
        quantity += d;
    }
    void decreaseQuantity(int d = 1) {
        if (d <= 0) throw invalid_argument("Decrease delta must be > 0");
        if (quantity - d < 0) throw logic_error("Quantity cannot go negative");
        quantity -= d;
    }
    void _assign(typeOfProduct t, const string& n, int q, double p) { // призначити, перезаписати
        if (n.empty()) throw invalid_argument("Empty product name");
        if (q <= 0)     throw invalid_argument("Quantity must be > 0");
        if (p < 0.0)    throw invalid_argument("Price must be >= 0");
        type = t;
        name = n;
        quantity = q;
        price = p;
    }
};

class Cart {
private:
    vector<CartItem> items;
public:
    void addItem(const CartItem& it) {
        items.push_back(it);
    }
    void removeItem(int index) {
        if (index <= 0 || index > (int)items.size())
            throw out_of_range("Cart item index out of range");
        items.erase(items.begin() + index - 1);
        cout << "Item #" << index << " removed.\n";
    }
    void clear() {
        items.clear();
    }
    double calculateTotal() const {
        double s = 0.0;
        for (size_t i = 0; i < items.size(); i++) s += items[i].getTotalPrice();
        return s;
    }
    void displayCart() const {
        if (items.empty()) {
            cout << "Cart is empty.\n";
            return;
        }
        title("Your Cart");
        cout << left << setw(32) << "Name" << setw(6) << "Qty\t" << right << setw(14) << "Price" << setw(14) << "Sum" << "\n";
        hr();
        for (size_t i = 0; i < items.size(); i++) {
            cout << right << setw(2) << (i + 1) << ") ";
            items[i].displayInfo();
        }
        hr();
        cout << right << setw(55) << "Total: " << right << setw(10) << fixed << setprecision(2) << calculateTotal() << " UAH\n";
        hr('=');
    }
    vector<CartItem> getItems() const {
        return items;
    }
    bool isEmpty() const {
        return items.empty();
    }
};

enum sizeOfPizza { none = 0, Small = 20, Medium = 30, Large = 40 };

class Pizza {
private:
    string name;
    vector<string> ingredients;
    int sizeInCm;
    double price;
    static bool _validSize(int s) {
        return s == Small || s == Medium || s == Large;
    }
public:
    Pizza() : name(""), ingredients{}, sizeInCm(none), price(0.0) {}
    Pizza(string n, vector<string> ingr, int size, double p)
        : name(n), ingredients(ingr), sizeInCm(size), price(p) {
        if (name.empty()) throw invalid_argument("Pizza name is empty");
        if (!_validSize(size)) throw invalid_argument("Pizza size must be 20/30/40");
        if (price < 0.0) throw invalid_argument("Pizza price must be >= 0");
    }
    virtual void displayInfo() const {
        cout << left << setw(28) << name
            << "Size: " << setw(3) << sizeInCm << " cm\tPrice: " << right << setw(9) << fixed << setprecision(2) << price << " UAH\n";

        cout << "    " << left << setw(14) << "Ingredients: ";
        for (size_t i = 0; i < ingredients.size(); i++) {
            cout << ingredients[i];
            if (i + 1 < ingredients.size()) cout << ", ";
        }
        cout << "\n";
    }
    void displayRowWithLine(int index) const {
        cout << right << setw(2) << index << ". ";
        displayInfo();
        hr();
    }

    string getName() const {
        return name;
    }
    int    getSize() const {
        return sizeInCm;
    }
    double getPrice() const {
        return price;
    }
    vector<string> getIngredients() const {
        return ingredients;
    }

    void setName(const string& n) {
        if (n.empty()) throw invalid_argument("Pizza name is empty");
        name = n;
    }
    void setSize(int s) {
        if (!_validSize(s)) throw invalid_argument("Pizza size must be 20/30/40");
        sizeInCm = s;
    }
    void setPrice(double p) {
        if (p < 0.0) throw invalid_argument("Price must be >= 0");
        price = p;
    }
    void addIngredient(const string& i) {
        if (i.empty()) throw invalid_argument("Ingredient name is empty");
        ingredients.push_back(i);
    }
    void clearIngredients() {
        ingredients.clear();
    }
    void changeIngredient(const string& oldI, const string& newI) {
        if (newI.empty()) throw invalid_argument("New ingredient name is empty");
        for (size_t i = 0; i < ingredients.size(); i++)
            if (ingredients[i] == oldI) {
                ingredients[i] = newI;
                return;
            }
        throw out_of_range("Ingredient to change not found: " + oldI);
    }
};
class CustomPizza : public Pizza {
public:
    CustomPizza() : Pizza() {}
    CustomPizza(string n, vector<string> ing, int s, double p) : Pizza(n, ing, s, p) {}
    void setCustomName(const string& n) {
        setName(n);
    }
    void displayInfo() const override {
        cout << "(Custom) ";
        Pizza::displayInfo();
    }
};

class Drink {
    string name;
    double volumeInLiters;
    double price;
public:
    Drink() : name(""), volumeInLiters(0.0), price(0.0) {}
    Drink(string n, double v, double p) : name(n), volumeInLiters(v), price(p) {
        if (name.empty()) throw invalid_argument("Drink name is empty");
        if (volumeInLiters <= 0.0) throw invalid_argument("Drink volume must be > 0");
        if (price < 0.0) throw invalid_argument("Drink price must be >= 0");
    }
    void displayInfo() const {
        cout << left << setw(28) << name
            << "Volume: " << setw(3) << volumeInLiters << " L\tPrice: " << right << setw(9) << fixed << setprecision(2) << price << " UAH\n";
    }
    string getName() const {
        return name;
    }
    double getPrice() const {
        return price;
    }
    double getVolume() const {
        return volumeInLiters;
    }

    void setName(const string& n) {
        if (n.empty()) throw invalid_argument("Drink name is empty");
        name = n;
    }
    void setPrice(double p) {
        if (p < 0.0) throw invalid_argument("Price must be >= 0");
        price = p;
    }
    void setVolume(double v) {
        if (v <= 0.0) throw invalid_argument("Volume must be > 0");
        volumeInLiters = v;
    }
};

// constructors for CartItem
CartItem::CartItem(const Pizza& pizza, int quantity) {
    _assign(PizzaType, pizza.getName(), quantity, pizza.getPrice());
}
CartItem::CartItem(const Drink& drink, int quantity) {
    _assign(DrinkType, drink.getName(), quantity, drink.getPrice());
}

// ingredients and store
struct Ingredient {
    int id{ 0 };
    string name;
    double price{ 0.0 };
    int stockQty{ 0 };
    bool isAvailable{ true };
};
class IngredientStore {
    vector<Ingredient> items;
    int nextId = 1;
public:
    int add(const string& name, double price, int stock, bool avail) {
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
    bool remove(int id) {
        for (size_t i = 0; i < items.size(); i++) if (items[i].id == id) {
            items.erase(items.begin() + i);
            return true;
        }
        throw out_of_range("Ingredient ID not found");
    }
    bool edit(int id, const string& nm, double pr, int stock, bool avail) {
        if (nm.empty()) throw invalid_argument("Ingredient name empty");
        if (pr < 0.0)   throw invalid_argument("Ingredient price < 0");
        if (stock < 0)  throw invalid_argument("Ingredient stock < 0");
        for (size_t i = 0; i < items.size(); i++) if (items[i].id == id) {
            items[i].name = nm;
            items[i].price = pr;
            items[i].stockQty = stock;
            items[i].isAvailable = avail;
            return true;
        }
        throw out_of_range("Ingredient ID not found");
    }
    const Ingredient* getById(int id) const {
        for (size_t i = 0; i < items.size(); i++) if (items[i].id == id) return &items[i];
        return nullptr;
    }
    const Ingredient* getByName(const string& nm) const {
        for (size_t i = 0; i < items.size(); i++) if (items[i].name == nm) return &items[i];
        return nullptr;
    }
    vector<Ingredient> list() const {
        return items;
    }
    void clear() {
        items.clear();
        nextId = 1;
    }

    void display() const {
        title("INGREDIENT STOCK");
        if (items.empty()) {
            cout << "(Empty)\n";
            return;
        }
        cout << left << setw(5) << "ID" << setw(28) << "Name" << right << setw(12) << "Price, UAH" << right << setw(10) << "Stock" << right << setw(10) << "Avail" << "\n";
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
};

// CustomPizzaBuilder
class CustomPizzaBuilder {
    string name = "Your Recipe";
    vector<string> chosenIngredients;
    int sizeCm = Medium;
    double basePrice = 60.0; // тісто
    double sizeMultiplier = 1.0;
    const IngredientStore* store{ nullptr };
    static bool _validSize(int s) {
        return s == Small || s == Medium || s == Large;
    }
public:
    CustomPizzaBuilder(const IngredientStore* s) : store(s) {}
    CustomPizzaBuilder& setName(const string& n) {
        if (n.empty()) throw invalid_argument("Custom pizza name empty");
        name = n;
        return *this;
    }
    CustomPizzaBuilder& setSize(int cm) {
        if (!_validSize(cm)) throw invalid_argument("Custom size must be 20/30/40");
        sizeCm = cm;
        if (cm == Small)  sizeMultiplier = 0.9;
        else if (cm == Medium) sizeMultiplier = 1.0;
        else if (cm == Large)  sizeMultiplier = 1.2;
        return *this;
    }
    CustomPizzaBuilder& addIngredientByName(const string& ingName) {
        if (!store) throw logic_error("IngredientStore is null");
        const Ingredient* ing = store->getByName(ingName);
        if (!ing) throw out_of_range("No such ingredient: " + ingName);
        if (!ing->isAvailable) throw runtime_error("Ingredient unavailable: " + ingName);
        chosenIngredients.push_back(ing->name);
        return *this;
    }
    CustomPizza build() const {
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
};


// there are some code that was written by ChatGPT
static vector<string> splitCSV(const string& s) {
    vector<string> out;
    string cur;
    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == ',' || c == ';') {
            size_t a = 0, b = cur.size();
            while (a < b && (cur[a] == ' ' || cur[a] == '\t')) ++a;
            while (b > a && (cur[b - 1] == ' ' || cur[b - 1] == '\t')) --b;
            if (b > a) out.push_back(cur.substr(a, b - a));
            cur.clear();
        }
        else cur.push_back(c);
    }
    size_t a = 0, b = cur.size();
    while (a < b && (cur[a] == ' ' || cur[a] == '\t')) ++a;
    while (b > a && (cur[b - 1] == ' ' || cur[b - 1] == '\t')) --b;
    if (b > a) out.push_back(cur.substr(a, b - a));
    return out;
}

static bool pizzaHasAll(const Pizza& P, const vector<string>& need) {
    const vector<string> ing = P.getIngredients();
    for (size_t k = 0; k < need.size(); ++k) {
        bool has = false;
        for (size_t j = 0; j < ing.size(); ++j) if (ing[j] == need[k]) {
            has = true;
            break;
        }
        if (!has) return false;
    }
    return true;
}

static bool pizzaHasAny(const Pizza& P, const vector<string>& need) {
    const vector<string> ing = P.getIngredients();
    for (size_t k = 0; k < need.size(); ++k) {
        for (size_t j = 0; j < ing.size(); ++j) if (ing[j] == need[k]) return true;
    }
    return false;
}

// more classes
class Menu {
private:
    vector<Pizza> pizzas;
    vector<Drink> drinks;
public:
    void addPizza(const Pizza& p) {
        pizzas.push_back(p);
    }
    void addDrink(const Drink& d) {
        drinks.push_back(d);
    }

    void removePizza(int index) {
        if (index <= 0 || index > (int)pizzas.size())
            throw out_of_range("Pizza index out of range");
        pizzas.erase(pizzas.begin() + index - 1);
        cout << "Pizza #" << index << " removed.\n";
    }
    void removeDrink(int index) {
        if (index <= 0 || index > (int)drinks.size())
            throw out_of_range("Drink index out of range");
        drinks.erase(drinks.begin() + index - 1);
        cout << "Drink #" << index << " removed.\n";
    }

    int findPizzaByName(const string& n) const {
        for (int i = 0; i < (int)pizzas.size(); i++) if (pizzas[i].getName() == n) return i;
        return -1;
    }
    int findDrinkByName(const string& n) const {
        for (int i = 0; i < (int)drinks.size(); i++) if (drinks[i].getName() == n) return i;
        return -1;
    }

    void findPizzaByIngredient(const string& ingredient) const {
        title(string("Search pizzas by ingredient: ") + ingredient);
        int found = 0;
        for (size_t i = 0; i < pizzas.size(); i++) {
            const vector<string>& ing = pizzas[i].getIngredients();
            bool has = false;
            for (size_t j = 0; j < ing.size(); ++j) if (ing[j] == ingredient) {
                has = true;
                break;
            }
            if (has) pizzas[i].displayRowWithLine(++found);
        }
        if (found == 0) cout << "Not found.\n";
    }
    void findPizzasByMulti(const vector<string>& keys, bool allMode) const {
        title(allMode ? "Search (ALL ingredients)" : "Search (ANY ingredient)");
        int found = 0;
        for (size_t i = 0; i < pizzas.size(); i++) {
            bool ok = allMode ? pizzaHasAll(pizzas[i], keys) : pizzaHasAny(pizzas[i], keys);
            if (ok) pizzas[i].displayRowWithLine((int)++found);
        }
        if (found == 0) cout << "Not found.\n";
    }

    void displayPizzas() const {
        title("PIZZA MENU");
        if (pizzas.empty()) {
            cout << "(No pizzas)\n";
            return;
        }
        cout << left << setw(4) << "No" << setw(26) << "Name" << setw(10) << "Size" << setw(10) << "" << right << setw(12) << "Price" << "\n";
        hr();
        for (size_t i = 0; i < pizzas.size(); i++) pizzas[i].displayRowWithLine((int)i + 1);
    }
    void displayDrinks() const {
        title("DRINKS MENU");
        if (drinks.empty()) {
            cout << "(No drinks)\n";
            return;
        }
        for (size_t i = 0; i < drinks.size(); i++) {
            cout << right << setw(2) << (i + 1) << ". ";
            drinks[i].displayInfo();
        }
        hr('=');
    }
    void displayMenu() const {
        displayPizzas();
        displayDrinks();
    }

    vector<Pizza> getPizzas() const {
        return pizzas;
    }
    vector<Drink> getDrinks() const {
        return drinks;
    }

    // save/load to/from file(split written by ChatGPT for comfort in using)
    bool saveToFile(const string& path, const string& pzName, const string& pzAddr, const IngredientStore& store) const {
        ofstream f(path.c_str(), ios::out | ios::trunc);  /*ios::out — відкриваємо на запис.  ios::trunc — обрізаємо файл до довжини 0 (перезапис “з нуля”).Якщо файл існував — вміст стирається.*/
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
            for (size_t j = 0; j < ing.size(); ++j) {
                f << ing[j];
                if (j + 1 < ing.size()) f << ",";
            }
            f << "\n";
        }
        return true;
    }
    static vector<string> splitBy(const string& s, char delim) {
        vector<string> parts;
        string cur;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == delim) {
                parts.push_back(cur);
                cur.clear();
            }
            else cur.push_back(s[i]);
        }
        parts.push_back(cur);
        return parts;
    }
    bool loadFromFile(const string& path, string& pzName, string& pzAddr, IngredientStore& store) {
        ifstream f(path.c_str());
        if (!f.is_open()) throw ios_base::failure("Cannot open file: " + path);

        pizzas.clear();
        drinks.clear();
        store.clear();

        string line;
        int ln = 0;
        while (getline(f, line)) {
            ++ln;
            if (line.size() < 3) continue;
            vector<string> parts = splitBy(line, '|');
            if (parts.empty()) continue;

            if (parts[0] == "PIZZERIA") {
                if (parts.size() < 3) throw runtime_error("Bad PIZZERIA line " + to_string(ln));
                pzName = parts[1];
                pzAddr = parts[2];
            }
            else if (parts[0] == "ING") {
                if (parts.size() < 6) throw runtime_error("Bad ING line " + to_string(ln));
                double price = stod(parts[3]);
                int stock = stoi(parts[4]);
                int avail = stoi(parts[5]);
                store.add(parts[2], price, stock, (avail != 0));
            }
            else if (parts[0] == "DR") {
                if (parts.size() < 4) throw runtime_error("Bad DR line " + to_string(ln));
                double vol = stod(parts[2]);
                double pr = stod(parts[3]);
                drinks.push_back(Drink(parts[1], vol, pr));
            }
            else if (parts[0] == "PZ") {
                if (parts.size() < 5) throw runtime_error("Bad PZ line " + to_string(ln));
                int size = stoi(parts[2]);
                double pr = stod(parts[3]);
                vector<string> ings = splitCSV(parts[4]);
                pizzas.push_back(Pizza(parts[1], ings, size, pr));
            }
            else {
                throw runtime_error("Unknown record '" + parts[0] + "' at line " + to_string(ln));
            }
        }
        return true;
    }
};

// main class pizzeria
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
    Pizzeria() : name(""), address(""), menu(), store(), users{}, admins{}, carts{} {}
    Pizzeria(const string& n, const string& a) : name(n), address(a), menu(), store(), users{}, admins{}, carts{} {}

    string getName() const {
        return name;
    }
    string getAddress() const {
        return address;
    }
    void setName(const string& n) {
        name = n;
    }
    void setAddress(const string& a) {
        address = a;
    }
    Menu& getMenu() {
        return menu;
    }
    const Menu& getMenu() const {
        return menu;
    }
    IngredientStore& getStore() {
        return store;
    }
    const IngredientStore& getStore() const {
        return store;
    }
    void showMenu() const {
        menu.displayMenu();
    }
    void addUser(const User& u) {
        users.push_back(u);
    }
    void addAdmin(const Admin& a) {
        admins.push_back(a);
    }

    int newCart() {
        carts.push_back(Cart{});
        return (int)carts.size();
    }
    bool validcartNumber(int cartNumber) const {
        return cartNumber > 0 && cartNumber <= (int)carts.size();
    }


    double checkoutCart(int cartNumber, const string& cashier, const string& paymentMethod, double delivery = 0.0, double discount = 0.0) {
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

    bool saveAll(const string& path) {
        return menu.saveToFile(path, name, address, store);
    }
    bool loadAll(const string& path) {
        string n = name, a = address;
        bool ok = menu.loadFromFile(path, n, a, store);
        if (ok) {
            name = n;
            address = a;
        }
        return ok;
    }

    // ADMIN MENU FUNCTIONS
    void addPizza() {
        cout << "Pizza name: ";
        string name;
        getline(cin, name);
        int size = readInt("Size (20/30/40): ");
        double price = readDouble("Price: ");
        int k = readInt("Ingredients count: ");
        vector<string> ing;
        for (int i = 0; i < k; ++i) {
            cout << "  Ingredient #" << (i + 1) << ": ";
            string s;
            getline(cin, s);
            if (!s.empty()) ing.push_back(s);
        }
        menu.addPizza(Pizza(name, ing, size, price));
        cout << "Pizza added.\n";
    }

    void deletePizza() {
        menu.displayPizzas();
        int index = readInt("Pizza number to delete: ");
        menu.removePizza(index);
    }

    void addDrink() {
        cout << "Drink name: ";
        string n;
        getline(cin, n);
        double v = readDouble("Volume (L): ");
        double p = readDouble("Price: ");
        menu.addDrink(Drink(n, v, p));
        cout << "Drink added.\n";
    }

    void deleteDrink() {
        menu.displayDrinks();
        int index = readInt("Drink number to delete: ");
        menu.removeDrink(index);
    }

    void searchPizzaByOneIngredient() const {
        cout << "Ingredient: ";
        string q;
        getline(cin, q);
        menu.findPizzaByIngredient(q);
    }

    void viewStore() const {
        store.display();
    }

    void addIngredient() {
        cout << "Ingredient name: ";
        string n;
        getline(cin, n);
        double pr = readDouble("Price (UAH): ");
        int st = readInt("Stock (pcs): ");
        int av = readInt("Available? (1/0): ");
        store.add(n, pr, st, av != 0);
        cout << "Ingredient added.\n";
    }

    void editIngredient() {
        store.display();
        int id = readInt("Ingredient ID: ");
        cout << "New name: ";
        string n;
        getline(cin, n);
        double pr = readDouble("New price: ");
        int st = readInt("New stock: ");
        int av = readInt("Available? (1/0): ");
        if (store.edit(id, n, pr, st, av != 0)) cout << "Updated.\n";
    }

    void deleteIngredient() {
        store.display();
        int id = readInt("Ingredient ID to delete: ");
        if (store.remove(id)) cout << "Deleted.\n";
    }

    void save() {
        cout << "File path (e.g., db.txt): ";
        string p;
        getline(cin, p);
        if (saveAll(p)) cout << "Saved.\n";
    }

    void load() {
        cout << "File path: ";
        string p;
        getline(cin, p);
        if (loadAll(p)) cout << "Loaded.\n";
    }

    void multiIngredientSearch(bool all) const {
        cout << "Enter ingredients separated by commas: ";
        string line;
        getline(cin, line);
        vector<string> keys = splitCSV(line);
        menu.findPizzasByMulti(keys, all);
    }

    void editPizza() {
        vector<Pizza> P = menu.getPizzas();
        menu.displayPizzas();
        int index = readInt("Pizza number to EDIT: ");
        if (index <= 0 || index > (int)P.size()) throw out_of_range("Invalid pizza index");
        Pizza old = P[index - 1];

        cout << "New name (blank=keep '" << old.getName() << "'): ";
        string nm;
        getline(cin, nm);
        if (nm.empty()) nm = old.getName();

        int sz = readInt("New size (20/30/40, 0=keep): ");
        if (sz == 0) sz = old.getSize();

        double pr = readDouble("New price (-1=keep): ");
        if (pr < 0) pr = old.getPrice();

        vector<string> newIng = old.getIngredients();
        cout << "Change ingredients? (y/n): ";
        string yn;
        getline(cin, yn);
        if (!yn.empty() && (yn[0] == 'y' || yn[0] == 'Y')) {
            newIng.clear();
            cout << "Enter ingredients separated by commas: ";
            string line;
            getline(cin, line);
            newIng = splitCSV(line);
        }

        menu.removePizza(index);
        menu.addPizza(Pizza(nm, newIng, sz, pr));
        cout << "Pizza edited.\n";
    }


    // USER MENU FUNCTIONS
    void viewMenu() const {
        showMenu();
    }

    void addPizzaToCart(int cartNumber) {
        if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
        menu.displayPizzas();
        int index = readInt("Pizza number: ");
        int qty = readInt("Quantity: ");
        const vector<Pizza> P = menu.getPizzas();
        if (index <= 0 || index > (int)P.size()) throw out_of_range("Pizza number invalid");
        carts[cartNumber - 1].addItem(CartItem(P[index - 1], qty));
        cout << "Added.\n";
    }

    void addDrinkToCart(int cartNumber) {
        if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
        menu.displayDrinks();
        int index = readInt("Drink number: ");
        int qty = readInt("Quantity: ");
        const vector<Drink> D = menu.getDrinks();
        if (index <= 0 || index > (int)D.size()) throw out_of_range("Drink number invalid");
        carts[cartNumber - 1].addItem(CartItem(D[index - 1], qty));
        cout << "Added.\n";
    }

    void showCart(int cartNumber) const {
        if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
        carts[cartNumber - 1].displayCart();
    }

    void removeCartItem(int cartNumber) {
        if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
        carts[cartNumber - 1].displayCart();
        int index = readInt("Item number: ");
        carts[cartNumber - 1].removeItem(index);
    }

    void removeOnlyPizza(int cartNumber) {
        if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
        if (carts[cartNumber - 1].isEmpty()) {
            cout << "Cart is empty. Nothing to remove.\n";
            return;
        }
        vector<CartItem> items = carts[cartNumber - 1].getItems();
        bool found = false;
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].getType() == PizzaType) {
                cout << (i + 1) << ") " << items[i].getName() << " x" << items[i].getQuantity() << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No pizzas in cart.\n";
            return;
        }
        int index = readInt("Enter pizza item number to remove: ");
        if (index <= 0 || index > (int)items.size() || items[index - 1].getType() != PizzaType)
            throw out_of_range("Invalid pizza item number");
        carts[cartNumber - 1].removeItem(index);
    }

    void removeOnlyDrink(int cartNumber) {
        if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
        if (carts[cartNumber - 1].isEmpty()) {
            cout << "Cart is empty. Nothing to remove.\n";
            return;
        }
        vector<CartItem> items = carts[cartNumber - 1].getItems();
        bool found = false;
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].getType() == DrinkType) {
                cout << (i + 1) << ") " << items[i].getName() << " x" << items[i].getQuantity() << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No drinks in cart.\n";
            return;
        }
        int index = readInt("Enter drink item number to remove: ");
        if (index <= 0 || index > (int)items.size() || items[index - 1].getType() != DrinkType)
            throw out_of_range("Invalid drink item number");
        carts[cartNumber - 1].removeItem(index);
    }

    void searchPizzaByOneIngredient_User() const {
        cout << "Ingredient: ";
        string q;
        getline(cin, q);
        menu.findPizzaByIngredient(q);
    }

    void buildCustomPizza(int cartNumber) {
        if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
        const IngredientStore& st = store;
        st.display();
        CustomPizzaBuilder b(&st);
        cout << "Custom pizza name: ";
        string nm;
        getline(cin, nm);
        b.setName(nm);
        int sz = readInt("Size (20/30/40): ");
        b.setSize(sz);
        cout << "Enter ingredients separated by commas: ";
        string line;
        getline(cin, line);
        vector<string> keys = splitCSV(line);
        for (size_t i = 0; i < keys.size(); i++) b.addIngredientByName(keys[i]);
        CustomPizza cp = b.build();
        cout << "\nYour pizza:\n";
        cp.displayInfo();
        int qty = readInt("How many to add to cart?: ");
        carts[cartNumber - 1].addItem(CartItem(cp, qty));
        cout << "Added to cart.\n";
    }

    void multiIngredientSearch_User(bool all) const {
        cout << "Enter ingredients separated by commas: ";
        string line;
        getline(cin, line);
        vector<string> keys = splitCSV(line);
        menu.findPizzasByMulti(keys, all);
    }

    void checkout(int cartNumber) {
        if (!validcartNumber(cartNumber)) throw out_of_range("Cart number invalid");
        double delivery = readDouble("Delivery (0 - pickup): ");
        double discount = readDouble("Discount (0 - none): ");
        string cashier = "Vasia";
        string pay;
        while (true) {
            cout << "Payment type (cash/card): ";
            getline(cin, pay);

            if (pay == "cash" || pay == "card") {
                break; // коректне значення — вихід з циклу
            }
            else {
                cout << "Payment must be 'cash' or 'card'. Try again.\n";
            }
        }
        double total = checkoutCart(cartNumber, cashier, pay, delivery, discount);
        cout << "Payment accepted. Total: " << fixed << setprecision(2) << total << " UAH\n";
    }
};

// for use in adminMenu
void userMenu(Pizzeria& pz);

// admin menu
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
            if (c == 1) {
                pz.showMenu();
            }
            else if (c == 2) {
                pz.addPizza();
            }
            else if (c == 3) {
                pz.deletePizza();
            }
            else if (c == 4) {
                pz.addDrink();
            }
            else if (c == 5) {
                pz.deleteDrink();
            }
            else if (c == 6) {
                pz.searchPizzaByOneIngredient();
            }
            else if (c == 7) {
                pz.viewStore();
            }
            else if (c == 8) {
                pz.addIngredient();
            }
            else if (c == 9) {
                pz.editIngredient();
            }
            else if (c == 10) {
                pz.deleteIngredient();
            }
            else if (c == 11) {
                pz.save();
            }
            else if (c == 12) {
                pz.load();
            }
            else if (c == 13) {
                pz.multiIngredientSearch(true);   // all
            }
            else if (c == 14) {
                pz.multiIngredientSearch(false);   // any
            }
            else if (c == 15) {
                pz.editPizza();
            }
            else if (c == 16) {
                userMenu(pz);
            }
            else  cout << "Unknown choice.\n";
        }
        catch (const ios_base::failure& e) {
            cout << "I/O error: " << e.what() << "\n";
        }
        catch (const out_of_range& e) {
            cout << "Out of range: " << e.what() << "\n";
        }
        catch (const invalid_argument& e) {
            cout << "Invalid argument: " << e.what() << "\n";
        }
        catch (const logic_error& e) {
            cout << "Logic error: " << e.what() << "\n";
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
}



// user menu
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
            if (c == 1)  pz.viewMenu();
            else if (c == 2) {
                pz.addPizzaToCart(cartNumber);
            }
            else if (c == 3) {
                pz.addDrinkToCart(cartNumber);
            }
            else if (c == 4) {
                pz.showCart(cartNumber);
            }
            else if (c == 5) {
                pz.removeCartItem(cartNumber);
            }
            else if (c == 6) {
                pz.checkout(cartNumber);
            }
            else if (c == 7) {
                pz.searchPizzaByOneIngredient_User();
            }
            else if (c == 8) {
                pz.buildCustomPizza(cartNumber);
            }
            else if (c == 9) {
                pz.multiIngredientSearch_User(true);   // all
            }
            else if (c == 10) {
                pz.multiIngredientSearch_User(false);    // any
            }
            else if (c == 11) {
                pz.removeOnlyPizza(cartNumber);
            }
            else if (c == 12) {
                pz.removeOnlyDrink(cartNumber);
            }
            else              cout << "Unknown choice.\n";
        }
        catch (const ios_base::failure& e) {
            cout << "I/O error: " << e.what() << "\n";
        }
        catch (const out_of_range& e) {
            cout << "Out of range: " << e.what() << "\n";
        }
        catch (const invalid_argument& e) {
            cout << "Invalid argument: " << e.what() << "\n";
        }
        catch (const logic_error& e) {
            cout << "Logic error: " << e.what() << "\n";
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << "\n";
        }
    }
}


// demo data for pizzeria
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
int main() {

    try {
        Pizzeria pizzeria(" [ Not Sheet Pizza ]", "Independence Ave, 12");

        //if you want to see SO MUCH items in cart, just uncomment it
        loadDBTXT(pizzeria, "db.txt");

        title("WELCOME TO " + pizzeria.getName());
        cout << "- REGISTRATION -\n";
        cout << "Enter username: ";
        string username; getline(cin, username);
        cout << "Enter password: ";
        string password; getline(cin, password);
        cout << "Welcome, " << username << "!\n";
        setupDemoMenuAndStock(pizzeria);

        if (username == "admin" || username == "ADMIN") {
            pizzeria.addAdmin(Admin("admin", password));
            cout << "Logged in as administrator.\n";
            adminMenu(pizzeria);
        }
        else {
            pizzeria.addUser(User(username, password));
            cout << "Logged in as user.\n";
            userMenu(pizzeria);
        }

        hr('=');
        cout << "Thanks for choosing us! Have a great day!\n";
        return 0;
    }
    catch (const exception& e) {
        cerr << "Fatal error: " << e.what() << "\n";
        return 1; /* why 1, because 0 simply means successful
        completion of the program, and here there is an error*/
    }
    catch (...) {
        cerr << "Unknown fatal error.\n";
        return 1;
    }
}


