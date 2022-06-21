//
// Created by bartosz bugla on 28/05/2022.
//

#include "Register.h"

void Register::validate() {
    string err;
    if (email.empty() || password.empty() || name.empty() || secondName.empty()) {
        err = "Uzuepelnij wszystkie pola";
        throw err;
    }
    if (email.length() < 3) {
        err = "Email musi miec dlugosc 3 znakow";
        throw err;
    }
    if (password.length() < 3) {
        err = "Haslo musi miec dlugosc 3 znakow";
        throw err;
    }
    if (name.empty() || secondName.empty()) {
        err = "Imie i nazwisko nie moga byc puste.";
        throw err;
    }
}

void Register::show() {
    Clear();
    for (int i = 0; i < 40; i++)
        cout << color("*", Color::magenta);

    cout << endl;
    cout << "Email: " << color(email, Color::blue) << endl;
    cout << "Haslo: " << color(password, Color::blue) << endl;
    cout << "Imie: " << color(name, Color::blue) << endl;
    cout << "Nazwisko: " << color(secondName, Color::blue) << endl;


    for (int i = 0; i < 40; i++)
        cout << color("*", Color::magenta);
    cout << endl;

    !errorMessage.empty() && cout << color(errorMessage, Color::red) << endl;
    cout << "1. Wpisz email" << endl;
    cout << "2. Wpisz haslo" << endl;
    cout << "3. Wpisz imie" << endl;
    cout << "4. Wpisz nazwisko" << endl;
    cout << color("5. Zarejestruj sie", Color::blue) << endl;
    cout << "6. Mam juz konto." << endl;
    for (int i = 0; i < 40; i++)
        cout << color("*", Color::magenta);
    cout << endl;


}

void Register::render() {
    User *newUser = new User();
    User *checkEmailUser;
    while (true) {
        show();
        errorMessage = "";
        string err;
        try {
            cout << "Twoj wybor:";
            int choice = inputNum();
            show();
            switch (choice) {

                case 1:
                    cout << "Wpisz email: ";
                    email = input();
                    if (email.length() < 3) {
                        err = "Email musi miec dlugosc 3 znakow";
                        throw err;
                    }
                    checkEmailUser = User::findUserByEmail(email);

                    if (!checkEmailUser->email.empty()) {
                        err = "Ten email jest zajety.\n Sproboj ponownie.";
                        email = "";
                        throw err;
                    }

                    continue;
                case 2:
                    cout << "Podaj haslo: ";
                    password = input();
                    if (password.length() < 3) {
                        err = "Haslo musi miec dlugosc 3 znakow";
                        throw err;
                    }
                    continue;
                case 3:
                    cout << "Podaj imie: ";
                    name = input();
                    continue;
                case 4:
                    cout << "Podaj nazwisko: ";
                    secondName = input();
                    continue;
                case 5:

                    validate();
                    newUser->setEmail(password);
                    newUser->setPassword(password);
                    newUser->setSecondName(secondName);
                    newUser->setName(name);
                    newUser->reg();

                    View::user = User::findUserByEmail(email);
                    setScreen(dashboard);
                    email = "";
                    password = "";
                    name = "";
                    secondName = "";
                    return;
                case 6:
                    setScreen(login);
                    email = "";
                    password = "";
                    name = "";
                    secondName = "";
                    return;
                default:
                    err = "Podales zla liczbe.";
                    throw err;
            }

        } catch (const string &err) {
            if (err == "NOT_FOUND") {
                errorMessage = "";
                continue;
            }
            errorMessage = err;
        }

    }
}