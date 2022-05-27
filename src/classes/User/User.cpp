//
// Created by bartosz bugla on 24/05/2022.
//

#include "User.h"

User::User()
{

};
void User::login(string email, string password){

};
void User::getMe(const string &byEmail){
    if(byEmail == "bartek"){
        //załadowanie z bazy danych
        this->email = "bartek";
        this->_password = "123";
        this->name = "bartek";
        this->secondName="Bugla";
        this->_id = 50;
    }

}
void User::reg()
{
    int correct{};
    while(correct!=1) {
        cout << "podaj mail\n";
        cin >> User::email;
        cout << "podaj haslo\n";
        cin >> User::_password;
        cout << "podaj imie\n";
        cin >> User::name;
        cout << "podaj nazwisko\n";
        cin >> User::secondName;
        cout << "email = " << User::email << endl;
        cout << "haslo = " << User::_password << endl;
        cout << "imie = " << User::name << endl;
        cout << "nazwisko = " << User::secondName << endl;
        cout << "Czy podano prawidlowe dane? 1-tak/2-nie";
        cin>>correct;
    }

    fstream plik;
    plik.open("baza_uzytkownikow.txt", ios::out | ios::app);
    if(plik.is_open())
    {
        plik<<User::email+";"+User::_password+";"+User::name+";"+User::secondName+"\n";
        plik.close();
        cout<<"Pomyslnie zarejestrowano uzytkownika";
    }
    //ogarnac jak zrobic zeby po zarejestrowaniu cofalo do wyboru ekranu ponownie

    else
        cout<<"Nie mozna zarejestrowac uzytkownika, spróbuj ponownie pozniej\n";



}