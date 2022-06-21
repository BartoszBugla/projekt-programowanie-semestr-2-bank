//
// Created by bartosz bugla on 24/05/2022.
//

#include "Login.h"

void Login::show() {
    Clear();

    for (int i = 0; i < 40; i++)
        cout << color("*", Color::magenta);

    cout << endl;
    cout << "Email: " << color(email, Color::blue) << endl;
    cout << "Haslo: " << color(password, Color::blue) << endl;


    for (int i = 0; i < 40; i++)
        cout << color("*", Color::magenta);
    cout << endl;

    !errorMessage.empty() && cout << color(errorMessage, Color::red) << endl;
    cout << "1. Wpisz email" << endl;
    cout << "2. Wpisz haslo" << endl;
    cout << color("3. Zaloguj sie", Color::blue) << endl;
    cout << "4. Nie mam konta." << endl;
    for (int i = 0; i < 40; i++)
        cout << color("*", Color::magenta);
    cout << endl;


}

void Login::render() {
    User logowanie;

    while (true) {
        show();
        User *checkEmail;
        try {
            cout << "Twoj wybor:";
            int choice = inputNum();
            show();
            switch (choice) {
                case 1:
                    cout << "Wpisz email: ";
                    email = input();
                    checkEmail = User::findUserByEmail(email);
                    errorMessage = "";
                    continue;
                case 2:
                    cout << "Wpisz haslo: ";
                    password = input();
                    continue;
                case 3:
                    if (email == "admin" && password == "admin") {
                        setScreen(AdminDashboard);
                        return;
                    }
                    user = User::login(email, password);
                    setScreen(Screen::dashboard);
                    email = "";
                    password = "";
                    return;
                case 4:
                    setScreen(Screen::reg);
                    email = "";
                    password = "";
                    return;
                default:
                    return;
            }
        } catch (const string &err) {
            if (err == "NOT_FOUND") {
                errorMessage = "Nie znaleziono uzytkownika z takime emailem";
                email = "";
                continue;
            }
            errorMessage = err;
        }

    }
}
