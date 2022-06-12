//
// Created by bartosz bugla on 04/06/2022.
//

#include "CreateTransfer.h"

bool CreateTransfer::validate() {
    if (msg == "" || to == "" || value == 0) {
        return false;
    }
    return true;
}

void CreateTransfer::show() {

    Clear();
    bool isValid = validate();

    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;
    cout << "(Ty)Od: " << color(View::user->email, Color::blue) << endl;
    cout << "(1)Do: " << color(to, Color::blue) << endl;
    cout << "(2)Wartosc przelewu: " << color(to_string(value), Color::blue) << endl;
    cout << "(3)Wiadmomosc: " << color(msg, Color::blue) << endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;

    !errorMessage.empty() && cout << color(errorMessage, Color::red) << endl;
    cout << "Uzupelnij formularz" << endl;
    cout << "1.Wprowadz odbiorce" << endl;
    cout << "2.Wprowadz wartosc" << endl;
    cout << "3.Wprowadz wiadmosc" << endl;
    cout << "4.Wyjdz bez zapisu" << endl;
    isValid && cout << "5. wyslij przelew" << endl;

    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout << endl;

}

void CreateTransfer::render() {
    while (true) {
        show();

        cout << endl;
        cout << "Twoj wybor: ";
        int choice = inputNum();

        switch (choice) {

            case 1:
                cout << "Podaj Odbiorce: ";
                to = input();
                //check
                try {
                    User::findUserByEmail(to);
                    if (View::user->email == to) {
                        string message = "Nie mozesz wyslac sobie przelewu";
                        throw message;
                    }
                    errorMessage = "";
                } catch (const string &err) {
                    to = "";
                    errorMessage = err;
                    if (err == "NOT_FOUND") {
                        errorMessage = "Nie znaleziono uzytkownika z takim emailem";
                    }
                }

                continue;
            case 2:
                try {
                    cout << "Podaj ile chcesz przelać: ";
                    value = inputNum();
                    if (View::user->balance < value) {
                        string e = "Brak wystarczjacych srodkow";
                        throw e;
                    }
                    errorMessage = "";
                } catch (const string &err) {
                    errorMessage = err;
                    value = 0;
                    show();
                }
                continue;
            case 3:
                cout << "Podaj wiadomosc: ";
                msg = input();
                continue;
            case 4:
                msg = "";
                value = 0;
                to = "";
                setScreen(dashboard);
                return;
            case 5:
                Transfer newTransfer = Transfer(from, to, msg, float(value));
                createAndSaveTransfer(*View::user, newTransfer);
                setScreen(dashboard);
                return;
        }
    }


    //save
}