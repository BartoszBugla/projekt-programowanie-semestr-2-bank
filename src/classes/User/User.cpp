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

    if (emailCheck == "admin" && passwordCheck == "admin") {
        return true;
    } else {
        file.open("baza_uzytkownikow.txt", ios::in);

        if (file.is_open()) {

            while (!file.eof()) {
                file >> _id >> email >> _password >> name >> secondName;
                if (emailCheck == email && passwordCheck == _password) {
                    return true;
                }
            }
            if (!y) {
                cout << "Dane sa nieprawidlowe. Sprobuj ponownie." << endl;
            }
            file.close();
        }
    }

};

//get user by email


void User::setid() {
    int lines{};
    string line;
    fstream file;
    file.open("baza_uzytkownikow.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, line))
            ++lines;
        file.close();
    } else {
        string code = "FILE_NOT_OPENED";
        throw code;
    }
    _id = lines + 1;

}

bool User::reg() {
    fstream file;
    file.open("baza_uzytkownikow.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << _id;
        file << " " + email + " " + _password + " " + name + " " + secondName + "\n";
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
            if (arrayOfStrings[1] == byEmail) {
                newUser->_id = stoi(arrayOfStrings[0]);
                newUser->email = arrayOfStrings[1];
                newUser->_password = arrayOfStrings[2];
                newUser->name = arrayOfStrings[3];
                newUser->secondName = arrayOfStrings[4];
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