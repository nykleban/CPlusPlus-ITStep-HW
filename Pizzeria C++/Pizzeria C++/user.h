#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {
protected:
    string username;
    string password;
    bool isAdmin;
public:
    User();
    User(string u, string p, bool admin = false);
    string getUsername() const;
    string getPassword() const;
    bool getIsAdmin() const;
    void setUsername(const string& u);
    void setPassword(const string& p);
};

class Admin : public User {
public:
    Admin();
    Admin(string u, string p);
};

#endif 
