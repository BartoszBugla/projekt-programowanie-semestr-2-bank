//
// Created by bartosz bugla on 26/05/2022.
//


#include "common.h"

mt19937 generator(time(nullptr));

int random(int a, int b) {
    uniform_int_distribution<int> number(a, b);

    return number(generator);
}

void wait(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void Clear() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

string input() {
    string userInput;
    getline(cin >> ws, userInput);
    return userInput;
}

int inputNum() {
    string userInput;
    getline(cin >> ws, userInput);
    if (userInput.length() == 0) {
        string message = "Nic nie podałeś";
        throw message;
    }
    for (char i: userInput)
        if (i < '0' || i > '9') {
            string message = "Nie podales liczby";
            throw message;
        }
    return stoi(userInput);
}

string color(const string &text, Color colorId) {
    return "\x1b[" + to_string(colorId) + "m" + text + "\x1b[0m";
}

string *splitString(string s, const string &delimiter, int len) {
    size_t pos = 0;
    string token;
    auto *array = new string[len];
    int i = 0;
    s = s + delimiter;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        array[i] = token;
        i++;
        s.erase(0, pos + delimiter.length());
    }

    return array;
}