//
// Created by bartosz bugla on 28/05/2022.
//

#ifndef APLIKACJABANKOWA_REGISTER_H
#define APLIKACJABANKOWA_REGISTER_H

#include "../View.h"

class Register : public View {
private:
    void show();

    string errorMessage;

    string email, password, secondName, name;

    void validate();

public:
    void render();

};


#endif //APLIKACJABANKOWA_REGISTER_H
