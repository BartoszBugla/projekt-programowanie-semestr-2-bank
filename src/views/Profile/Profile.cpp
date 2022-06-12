//
// Created by bartosz bugla on 02/06/2022.
//

#include "Profile.h"

void Profile::show() {
    Clear();
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    cout << "Cześć " << color(View::user->name, Color::red) << " ";
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    cout << "1. Powrót" << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
//    !errorMessage.empty() && cout << color(errorMessage, Color::red) << endl;
}

void Profile::render() {
    show();
    cout << "Twoj wybór: ";
    int choice;

    try {
        choice = inputNum();
        if (choice > 5 || choice < 1) {
            string e = "Wpisz poprawną liczbę";
            throw e;
        }

//        errorMessage = "";
//        setMappedScreen(choice);

    } catch (const string &err) {
//        errorMessage = err;
        show();
        // nie przekieruje na 404
        setScreen(dashboard);
    }

    }