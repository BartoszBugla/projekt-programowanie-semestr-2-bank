//
// Created by bartosz bugla on 26/05/2022.
//

#ifndef APLIKACJABANKOWA_COMMON_H
#define APLIKACJABANKOWA_COMMON_H

#include <string>
#include <iostream>
#include <random>
#include <thread>

using namespace std;

void Clear();

int random(int a, int b);

void wait(int milliseconds);

string input();

int inputNum();

enum Color {
    black = 30,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
};

string color(const string &, Color);

#endif //APLIKACJABANKOWA_COMMON_H

