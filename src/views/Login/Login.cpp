//
// Created by bartosz bugla on 24/05/2022.
//

#include "Login.h"
void Login::render(){
    Clear();
    string email = "";
    string password= "";

    //kolory robimy w ten sposób
    //https://stackoverflow.com/questions/33309136/change-color-in-os-x-console-output
    //bo to dziala i na macu i windows (przynajmnije powinno XD)

    cout << "\x1b[32;47m Siema wpisz swoje dane aby kontynuwować \x1b[0m "<<endl;
    while(true){
        cout << "Podaj email: ";
        email = input();
        // z bazy danych
        // trzeba zrobić walidacja najpierw znaleśc w plikach czy jest taki email
        if(email == "bartek") break  ;
        cout << "Wpisz poprawny email"<<endl;
    }
    while(true){
        cout << "Podaj haslo: ";
        password = input();
        //a potem czy ten email ma takie haslo
        //to sa dane testowe
        if(password == "123")  break ;
        cout << "Wpisz poprawne haslo"<<endl;
    }

    user->getMe(email);
    setScreen(Screen::dashboard);





}