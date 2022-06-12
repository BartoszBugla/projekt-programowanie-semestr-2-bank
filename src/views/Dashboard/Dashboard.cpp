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
    cout << "Twoje Saldo to: " << View::user->balance << endl;
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
//    if (user->email == "") {
//        user->getMe("bartek");
//    }

    blikCode.generate_blik();
    Dashboard::show();
    //
    cout << "Twoj wybór: ";
    int choice;

    try {
        choice = inputNum();
        if (choice == 5) {
            View::user->balance += 500;
        }
        if (choice > 4 || choice < 1) {
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
        // nie przekieruje na 404
        setScreen(dashboard);
    }
    // clean
}

void::Dashboard::welcomeScreen()
{
    int num;
    cout<<color("Witaj w aplikacji banku", Color::magenta)<<endl;

    cout<<"1. rejestracja"<<endl;
    cout<<"2. logowanie"<<endl;
    do
    {
        num=inputNum();
    }while(num!=1 && num!=2);

    switch (num) {
        case 1:
            setScreen(reg);
            return;
        case 2:
            setScreen(login);
            return;
    }
}

