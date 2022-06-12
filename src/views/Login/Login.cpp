//
// Created by bartosz bugla on 24/05/2022.
//

#include "Login.h"

void Login::render() {
    //kolory robimy w ten sposób
    //https://stackoverflow.com/questions/33309136/change-color-in-os-x-console-output
    //bo to dziala i na macu i windows (przynajmnije powinno XD)
    bool x = false;
    Clear();
    string email = "";
    string password = "";
    User logowanie;
    do {
        cout << "Podaj email: ";
        email = input();
        cout << "Podaj haslo: ";
        password = input();
    } while (!logowanie.login(email, password));

    if (email == "admin" && password == "admin") {
        setScreen(Screen::AdminDashboard);
        return;
    }
    user = User::findUserByEmail(email);
    setScreen(Screen::dashboard);

}
