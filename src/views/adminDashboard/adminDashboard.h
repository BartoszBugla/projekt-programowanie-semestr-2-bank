//
// Created by Michał Bober on 10.06.2022.
//

#ifndef APLIKACJABANKOWA_ADMINDASHBOARD_H
#define APLIKACJABANKOWA_ADMINDASHBOARD_H

#include "../View.h"
#include "../../utils/common.h"
class adminDashboard:public View{
public:
    void render();
    void userData();
    void transferData();
    adminDashboard();
};
#endif //APLIKACJABANKOWA_ADMINDASHBOARD_H
