//
// Created by Michał Bober on 27.05.2022.
//

#include "blik.h"
#include "../utils/common.h"

blik::blik() {

}

int blik::generate_blik() {
    blik::blik_number = random(100000, 999999);
}

int blik::getBlik() {
    return blik::blik_number;
}
