//
// Created by bartosz bugla on 26/05/2022.
//

#include "Dashboard.h"


void Dashboard::setMappedScreen(int num) {
    //Todo dobrze to zrobic
    switch (num) {
        case 1:
            setScreen(dashboard);
            return;
        case 2:
            setScreen(profile);
            return;
        case 3:
            setScreen(dashboard);
            return;
        case 4:
            setScreen(leave);
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
    cout << "Twoje Saldo to" << endl;
    cout << "Twój kod blik to " << color(to_string(blikCode.getBlik()), Color::blue) << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    cout << "1.Historia przelewów." << endl;
    cout << "2.Profil użytkownika" << endl;
    cout << "3.Zrób przelew " << endl;
    cout << "4.Wyloguj sie" << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    !errorMessage.empty() && cout << color(errorMessage, Color::red) << endl;
}

void Dashboard::render() {
    //robocze te getme
    if (user->email == "") {
        user->getMe("bartek");
    }

    blikCode.generate_blik();
    Dashboard::show();
    //
    cout << "Twoj wybór: ";
    int choice;

    try {
        choice = inputNum();
        if (choice > 5 || choice < 1) {
            string e = "Wpisz poprawną liczbę";
            throw e;
        }

        errorMessage = "";
        setMappedScreen(choice);

    } catch (const string &err) {
        errorMessage = err;
        show();
        // nie przekieruje na 404
        setScreen(dashboard);
    }
    // clean


}