//
// Created by bartosz bugla on 24/05/2022.
//

#ifndef APLIKACJABANKOWA_USER_H
#define APLIKACJABANKOWA_USER_H

#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include "../../utils/common.h"

using namespace std;

class User {


private:
    int _id;
    string _password;
public:
    static User *findUserByEmail(const string &email);

    static User *getUsers();

    static User *login(string email, string login);

    string email;
    string name;
    string secondName;
    float balance = 0;

    User();

    int setid();

    void setName(string name);

    void setSecondName(string secondName);

    void setEmail(string email);

    int getid() {
        return _id;
    }

    bool reg();//rejestracja
    void setPassword(string pass) {
        _password = pass;
    }

    bool save();

    string getPassword() {
        return _password;
    }
};


#endif //APLIKACJABANKOWA_USER_H
