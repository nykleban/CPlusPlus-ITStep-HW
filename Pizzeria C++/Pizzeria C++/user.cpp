#include "user.h"

#include <string>

using namespace std;

User::User() : username(""), password(""), isAdmin(false) {}
User::User(string u, string p, bool admin) : username(u), password(p), isAdmin(admin) {}

string User::getUsername() const { return username; }
string User::getPassword() const { return password; }
bool User::getIsAdmin() const { return isAdmin; }
void User::setUsername(const string& u) { username = u; }
void User::setPassword(const string& p) { password = p; }

Admin::Admin() : User("", "", true) {}
Admin::Admin(string u, string p) : User(u, p, true) {}
