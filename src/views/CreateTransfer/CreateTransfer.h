//
// Created by bartosz bugla on 04/06/2022.
//

#ifndef APLIKACJABANKOWA_CREATETRANSFER_H
#define APLIKACJABANKOWA_CREATETRANSFER_H


#include "../View.h"
#include "../../classes/Transfer/Transfer.h"

class CreateTransfer : public View {
private:
    string to, msg;
    string from = View::user->email;
    string errorMessage;
    float value;

    void show();

    bool validate();

public:
    void render();
};


#endif //APLIKACJABANKOWA_CREATETRANSFER_H
