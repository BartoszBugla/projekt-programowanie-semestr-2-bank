//
// Created by bartosz bugla on 24/05/2022.
//

#ifndef APLIKACJABANKOWA_VIEW_H
#define APLIKACJABANKOWA_VIEW_H

#include "../classes/User/User.h"
#include "../utils/common.h"

enum Screen{
    login = 1,
    dashboard,
    reg,
    leave,
};
class View {

public:
    static User* user;
    static Screen screen;
    template<typename t> static void setScreen(t go){
        screen = static_cast<Screen>(go);
    }
};


#endif //APLIKACJABANKOWA_VIEW_H
