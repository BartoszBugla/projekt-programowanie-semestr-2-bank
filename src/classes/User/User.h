//
// Created by bartosz bugla on 24/05/2022.
//

#ifndef APLIKACJABANKOWA_USER_H
#define APLIKACJABANKOWA_USER_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class User {
private:
    int _id;
    string  _password;
public:
    //Trasnfer transfers;
    string email;
    string name;
    string secondName;
    User();
    bool login(string email, string login);
    void getMe(const string &email);
    bool reg();//rejestracja
    void setPassword(string pass){
        _password=pass;
    }
    string getPassword(){
       return  _password;
    }
};


#endif //APLIKACJABANKOWA_USER_H
