//
// Created by bartosz bugla on 24/05/2022.
//

#include "User.h"

User::User() {

};

bool User::login(string emailCheck, string passwordCheck) {
    fstream file;
    char wybor;
    bool y = false;

    file.open("baza_uzytkownikow.txt", ios::in);
    if (file.is_open()) {
        while (!file.eof()) {
            file >> email >> _password >> name >> secondName;
            if (emailCheck == email && passwordCheck == _password) {
                return true;
            }
        }
        if (y == false) {
            cout << "Dane sa nieprawidlowe. Sprobuj ponownie." << endl;
        }
        file.close();
    }

};

//get user by email
void User::getMe(const string &byEmail) {
    string line;
    fstream file;
    file.open("baza_uzytkownikow.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            string *arrayOfStrings = splitString(line, " ", 5);
            if (arrayOfStrings[0] == byEmail) {
                this->email = arrayOfStrings[0];
                this->_password = arrayOfStrings[1];
                this->name = arrayOfStrings[2];
                this->secondName = arrayOfStrings[3];
            }

        }

    }

}

void User::setid()
{
    int lines{};
    string line;
    fstream file;
    file.open("baza_uzytkownikow.txt", ios::in);
    if(file.is_open()){
        while(getline(file,line))
            ++lines;
        file.close();
    }
    else {
        string code = "FILE_NOT_OPENED";
        throw code;
    }
    _id=lines+1;

}

bool User::reg() {
    fstream file;
    file.open("baza_uzytkownikow.txt", ios::out | ios::app);
    if (file.is_open()) {
        file <<_id;
        file <<" " + email + " " + _password + " " + name + " " + secondName + "\n";
        file.close();
        return true;
    } else
        return false;
}

User *User::findUserByEmail(const string &byEmail) {
    string line;
    fstream file;
    User *newUser = new User();
    file.open("baza_uzytkownikow.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            string *arrayOfStrings = splitString(line, " ", 5);
            if (arrayOfStrings[0] == byEmail) {
                newUser->email = arrayOfStrings[0];
                newUser->_password = arrayOfStrings[1];
                newUser->name = arrayOfStrings[2];
                newUser->secondName = arrayOfStrings[3];
            }

        }
        if (newUser->email.empty()) {
            string code = "NOT_FOUND";
            throw code;
        }
        return newUser;
    } else {
        string code = "FILE_NOT_OPENED";
        throw code;
    }
};