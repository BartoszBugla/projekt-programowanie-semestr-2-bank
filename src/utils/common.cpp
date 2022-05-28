//
// Created by bartosz bugla on 26/05/2022.
//


#include "common.h"
mt19937 generator(time(nullptr));
int random(int a, int b ){
    uniform_int_distribution<int> number(a, b);

    return number(generator);
}
void wait(int milliseconds ){
    this_thread::sleep_for(chrono::milliseconds (milliseconds));
}
void Clear()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}
string input(){
    string userInput = "";
    getline(cin >> ws, userInput);
    return userInput;
}
int inputNum(){
    string userInput;
    getline(cin>>ws, userInput);
    if(userInput.length() == 0){
            string message = "Trzeba coś wpisac";
            throw message;
        }
    for(char i : userInput)
        if(i < '0' || i > '9'){
            string message = "Nie podales liczby";
            throw message;
    }
    return stoi(userInput);
}
