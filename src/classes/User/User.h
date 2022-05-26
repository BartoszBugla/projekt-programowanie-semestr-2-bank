//
// Created by bartosz bugla on 24/05/2022.
//

#ifndef APLIKACJABANKOWA_USER_H
#define APLIKACJABANKOWA_USER_H
#include <string>
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
    void login(string email, string login);
    void getMe(const string &email);
//    void register();

};


#endif //APLIKACJABANKOWA_USER_H
