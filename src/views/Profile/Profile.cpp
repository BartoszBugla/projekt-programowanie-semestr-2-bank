//
// Created by bartosz bugla on 02/06/2022.
//

#include "Profile.h"

void Profile::show() {
    Clear();
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    cout << "Cześć " << color(View::user->name, Color::red) << "\n";
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;

    cout << "1. Historia przelewow" << endl;
    cout << "2. Przeliczenie walut" << endl;
    cout << "3. Twoje dane" << endl;
    cout << "4. Powrot" << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
//    !errorMessage.empty() && cout << color(errorMessage, Color::red) << endl;
}

void Profile::render() {

    show();
    cout << "Twoj wybór: ";
    int num{};
    num = inputNum();
    while (num < 1 || num > 4) {
        num = inputNum();
    }
    if (num == 1)
        setScreen(TransferHistory);
    else if (num == 2)
        currencies();
    else if (num == 3)
        userInfo();
    else if (num == 4)
        setScreen(dashboard);
}

void Profile::currencies() {
    Clear();
    int balance = View::user->balance;
    float euro = View::user->balance * 4.66;
    float dolar = View::user->balance * 4.42;
    float funt = View::user->balance * 5.42;
    int num{};
    cout << color("Stan twojego konta w walutach: ", Color::green) << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    cout << balance << color("(PLN)", Color::green) << " = " << setprecision(5) << euro << color("(EUR)", Color::blue)
         << endl;
    cout << balance << color("(PLN)", Color::green) << " = " << setprecision(5) << dolar << color("(USD)", Color::blue)
         << endl;
    cout << balance << color("(PLN)", Color::green) << " = " << setprecision(5) << funt << color("(GBP)", Color::blue)
         << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    cout << "1.Powrot" << endl;
    cout << endl;
    cout << "Twoj wybor: ";
    num = inputNum();
    while (num != 1) {
        cout << "Twoj wybor: ";
        num = inputNum();
    }
    if (num == 1)
        setScreen(profile);
}

void Profile::userInfo() {
    int num{};
    Clear();
    cout << "Twoje dane: " << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    cout << color("imie: ", Color::green) << View::user->name << endl;
    cout << color("nazwisko: ", Color::green) << View::user->secondName << endl;
    cout << color("E-mail: ", Color::green) << View::user->email << endl;
    cout << color("haslo: ", Color::green) << View::user->getPassword() << endl;
    cout << color("stan konta: ", Color::green) << View::user->balance << " PLN" << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    cout << "1. Powrot" << endl;
    cout << "Twoj wybor: ";
    num = inputNum();
    while (num != 1) {
        cout << "Twoj wybor: ";
        num = inputNum();
    }
    if (num == 1)
        setScreen(profile);

}