//
// Created by Michał Bober on 27.05.2022.
//

#ifndef APLIKACJABANKOWA_BLIK_H
#define APLIKACJABANKOWA_BLIK_H

#include "../utils/common.h"

class blik {
private:
    int blik_number;
public:
    blik();

    int generate_blik();

    int getBlik();
};


#endif //APLIKACJABANKOWA_BLIK_H
