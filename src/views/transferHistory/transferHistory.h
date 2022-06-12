//
// Created by Michał Bober on 12.06.2022.
//

#ifndef APLIKACJABANKOWA_TRANSFERHISTORY_H
#define APLIKACJABANKOWA_TRANSFERHISTORY_H

#include "../View.h"
#include "fstream"
class transferHistory:public View {
public:
    void render();
    void getHistory(User &user);
    transferHistory();

};


#endif //APLIKACJABANKOWA_TRANSFERHISTORY_H
