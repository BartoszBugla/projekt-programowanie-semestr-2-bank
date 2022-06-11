//
// Created by bartosz bugla on 28/05/2022.
//

#include "Register.h"

void Register::render() {

    User* newUser = new User();
    int correct{};
    while(correct!=1) {
        cout <<"podaj mail"<<endl;
        newUser->email = input();
        cout << "podaj haslo\n";
        newUser->setPassword(input());
        cout << "podaj imie\n";
        newUser->name = input();
        cout << "podaj nazwisko\n";
        newUser->secondName = input();
        newUser->setid();
        cout << "email = " << newUser->email << endl;
        cout << "haslo = " <<newUser->getPassword() << endl;
        cout << "imie = " << newUser->name << endl;
        cout << "nazwisko = " << newUser->secondName << endl;
        cout << "Czy podano prawidlowe dane? 1-tak/2-nie\n";

        int correctInput =false;
        while(!correctInput){
            try{
                correct = inputNum();
                correctInput = true;
            }catch(string err){
                correctInput=false;
                cout<<err<<endl;
            }
        }
    }

    bool registerSuccess = newUser->reg();

    if(registerSuccess) {
        cout<<"Pomyslnie zarejestrowano uzytkownika\n";
    }else {
        cout<<"Nie mozna zarejestrowac uzytkownika, spróbuj ponownie pozniej\n";
    }
    setScreen(welcomeScreen);
}