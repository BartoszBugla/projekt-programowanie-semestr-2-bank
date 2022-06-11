//
// Created by bartosz bugla on 26/05/2022.
//

#ifndef APLIKACJABANKOWA_DASHBOARD_H
#define APLIKACJABANKOWA_DASHBOARD_H


#include "../View.h"
#include "../../utils/common.h"
#include <string>
#include "../../classes/blik.h"

class Dashboard : public View {
public:
    blik blikCode = blik();
    string errorMessage;

    void render();

    void show();

    void setMappedScreen(int);

    void welcomeScreen();
};


#endif //APLIKACJABANKOWA_DASHBOARD_H
