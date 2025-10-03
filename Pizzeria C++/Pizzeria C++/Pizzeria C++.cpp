#include <iostream>
#include <string>

using namespace std;

#include "pizzeria.h"
#include "interface.h"
#include "demo.h"
#include "user.h"
#include "helpers.h"

int main() {

    try {
        Pizzeria pizzeria(" [ Not Sheet Pizza ]", "Independence Ave, 12");
        
        //if you want to see SO MUCH items in cart, just uncomment it
        //loadDBTXT(pizzeria, "db.txt");


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
