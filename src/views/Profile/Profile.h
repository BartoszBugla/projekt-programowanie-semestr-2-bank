//
// Created by bartosz bugla on 02/06/2022.
//

#ifndef APLIKACJABANKOWA_PROFILE_H
#define APLIKACJABANKOWA_PROFILE_H


#include "../View.h"
#include "../../utils/common.h"
#include <iomanip>

class Profile : public View {
private:
    void show();

public:
    void render();
    void currencies();
    void userInfo();
};


#endif //APLIKACJABANKOWA_PROFILE_H
