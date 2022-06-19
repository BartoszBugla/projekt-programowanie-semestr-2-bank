//
// Created by bartosz bugla on 24/05/2022.
//

#include "User.h"

User::User() {

};

void User::setName(string name) {
    this->name = name;
}

void User::setSecondName(string secondName) {
    this->secondName = name;
}

void User::setEmail(string email) {
    this->email = email;
}


User *User::getUsers() {
    string line;
    fstream file;
    User *newUser = new User();
    // lines in file
    int lines = newUser->setid();
    User *users = new User[lines];
    int i = 0;
    file.open("baza_uzytkownikow.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            string *arrayOfStrings = splitString(line, " ", 6);

            users[i]._id = stoi(arrayOfStrings[0]);
            users[i].email = arrayOfStrings[1];
            users[i]._password = arrayOfStrings[2];
            users[i].name = arrayOfStrings[3];
            users[i].secondName = arrayOfStrings[4];
            users[i].balance = stof(arrayOfStrings[5]);
            i++;
        }
    }
    return users;

}

User *User::login(string emailCheck, string passwordCheck) {
    string err;

    if (emailCheck.empty()) {
        err = "Pole email nie może być puste";
        throw err;
    }
    User *user = User::findUserByEmail(emailCheck);
    if (user->getPassword() == passwordCheck) {
        return user;
    } else {
        err = "Haslo jest nieprawidlowe";
        throw err;
    }
};

//get user by email


int User::setid() {
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
    return _id;
}

bool User::reg() {
    fstream file;
    file.open("baza_uzytkownikow.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << _id;
        file << " " + email + " " + _password + " " + name + " " + secondName + " "
             << "500" << "\n";
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
            string *arrayOfStrings = splitString(line, " ", 6);
            if (arrayOfStrings[1] == byEmail) {
                newUser->_id = stoi(arrayOfStrings[0]);
                newUser->email = arrayOfStrings[1];
                newUser->_password = arrayOfStrings[2];
                newUser->name = arrayOfStrings[3];
                newUser->secondName = arrayOfStrings[4];
                newUser->balance = stof(arrayOfStrings[5]);
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

bool User::save() {
    fstream file("baza_uzytkownikow.txt");
    string line;
    ofstream newFile("temp.txt");
    string strTemp;
    string newFileString;

    if (file.is_open()) {
        while (getline(file, line)) {
            string *arrayOfStrings = splitString(line, " ", 10);
            if (stoi(arrayOfStrings[0]) == _id) {
                line = to_string(_id) + " "
                       + email + " "
                       + _password + " " +
                       name + " "
                       + secondName + " " +
                       to_string(balance) + "\n";
                newFileString += line;
            } else {
                newFileString += line + "\n";
            }
            delete[] arrayOfStrings;
        }
        newFile << newFileString;
        file.close();
        remove("baza_uzytkownikow.txt");
        rename("temp.txt", "baza_uzytkownikow.txt");
        newFile.close();
        return true;
    } else
        return false;

}