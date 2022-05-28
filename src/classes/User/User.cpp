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
bool User::reg()
{
    fstream file;
    file.open("baza_uzytkownikow.txt", ios::out | ios::app);
    if(file.is_open())
    {
        file<<email+";"+_password+";"+name+";"+secondName+"\n";
        file.close();
        return true;
    }
    else
        return false;





}