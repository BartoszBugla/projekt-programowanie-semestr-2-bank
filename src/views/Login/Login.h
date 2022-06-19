//
// Created by bartosz bugla on 24/05/2022.
//

#ifndef APLIKACJABANKOWA_LOGIN_H
#define APLIKACJABANKOWA_LOGIN_H

#include <iostream>
#include "../View.h"

using namespace std;

class Login : public View {
private:
    void show();

    string errorMessage;
    string email;
    string password;

public:
    void render();
};


#endif //APLIKACJABANKOWA_LOGIN_H
