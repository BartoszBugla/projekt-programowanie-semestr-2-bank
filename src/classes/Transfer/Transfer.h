//
// Created by bartosz bugla on 03/06/2022.
//

#ifndef APLIKACJABANKOWA_TRANSFER_H
#define APLIKACJABANKOWA_TRANSFER_H


#include "../User/User.h"

class Transfer {
private:
    float value;
    //narazie email ale lepiej zeby tu bylo id
    //from user to user chodzi
    string from;
    string to;
    string msg;
    //? nie wiem w sumie jak datę ogarnąc narazie
    string CreatedAt;
    float balanceBefore;
    float balanceAfter;

    static int calculateLinesInFile() {
        string line;
        fstream file;
        int counter = 0;
        file.open("baza_uzytkownikow.txt", ios::in);
        if (file.is_open()) {
            while (getline(file, line)) {
                counter++;
            }
        }
        return counter;
    }


public:
    Transfer(string from, string to, string msg, float value) {
        this->from = from;
        this->to = to;
        this->msg = msg;
        this->value = value;
    }

    void setValue(float val) {
        this->value = val;
    }

    float getValue() {
        return this->value;
    }

    void setFrom(string from) {
        this->from = from;
    }

    void setTo(string to) {
        this->to = to;
    }

    friend bool createAndSaveTransfer(const User &user, const Transfer &transfer) {
        fstream file;
        file.open("Transfers.txt", ios::out | ios::app);

        if (file.is_open()) {
            file << user.email + " " + transfer.to + " " + transfer.msg + " " + to_string(transfer.value);
            file << +" " + transfer.CreatedAt << user.balance << " " << user.balance - transfer.value
                 << "\n";
            file.close();
            return true;
        } else
            return false;
    }
};


#endif //APLIKACJABANKOWA_TRANSFER_H
