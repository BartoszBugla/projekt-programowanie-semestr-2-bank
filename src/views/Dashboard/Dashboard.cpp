//
// Created by bartosz bugla on 26/05/2022.
//

#include "Dashboard.h"


void Dashboard::setMappedScreen(int num) {

    switch (num) {
        case 1:
            setScreen(TransferHistory);
            return;
        case 2:
            setScreen(profile);
            return;
        case 3:
            setScreen(createTransferScreen);
            return;
        case 4:
            welcomeScreen();
            return;
        default:
            setScreen(404);
            return;
    }
}

void Dashboard::show() {
    Clear();
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    cout << "Cześć " << color(View::user->name, Color::red) << " ";
    cout << "Twoje Saldo to: " << color(to_string(int(View::user->balance)) + " PLN", Color::blue) << endl;
    cout << "Twój kod blik to " << color(to_string(blikCode.getBlik()), Color::blue) << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    cout << "1.Historia przelewów." << endl;
    cout << "2.Profil użytkownika" << endl;
    cout << "3.Zrób przelew " << endl;
    cout << "4.Wyloguj sie" << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::cyan);
    cout << endl;
    cout << "5. Zdeponuj 1" << endl;
    cout << "6. Zdeponuj 20" << endl;
    cout << "7. Zdeponuj 50" << endl;
    cout << "8. Zdeponuj 100" << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    !errorMessage.empty() && cout << color(errorMessage, Color::red) << endl;
}

void Dashboard::render() {
    blikCode.generate_blik();
    Dashboard::show();
    //
    cout << "Twoj wybór: ";
    int choice;

    try {
        string successMsg = color("Udało ci się zdeponować", Color::green);
        choice = inputNum();
        if (choice == 5) {
            View::user->balance += 1;
            View::user->save();
            throw successMsg;
        }
        if (choice == 6) {
            View::user->balance += 20;
            View::user->save();
            throw successMsg;
        }
        if (choice == 7) {
            View::user->balance += 50;
            View::user->save();
            throw successMsg;
        }
        if (choice == 8) {
            View::user->balance += 100;
            View::user->save();
            throw successMsg;

        }
        if (choice > 8 || choice < 1) {
            string e = "Wpisz poprawną liczbę";
            throw e;
        }
        if (choice == 3 && View::user->balance <= 0) {
            string e = "jestes bankrut :(";
            throw e;
        }
        errorMessage = "";
        setMappedScreen(choice);

    } catch (const string &err) {
        errorMessage = err;
        show();
        setScreen(dashboard);
    }
}

void Dashboard::welcomeScreen() {
    int num;
    Clear();
    cout << color("Witaj w aplikacji banku", Color::magenta) << endl;

    cout << "1. rejestracja" << endl;
    cout << "2. logowanie" << endl;
    string error;
    do {
        try {
            num = inputNum();
        } catch (string err) {
            error = err;
        }
    } while (num != 1 && num != 2 && error.empty() && num != 3);

    switch (num) {
        case 1:
            setScreen(reg);
            return;
        case 2:
            setScreen(login);
            return;
        case 3:
            setScreen(leave);
            return;
    }
}

