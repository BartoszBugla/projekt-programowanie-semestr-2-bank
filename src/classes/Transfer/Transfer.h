//
// Created by bartosz bugla on 03/06/2022.
//

#ifndef APLIKACJABANKOWA_TRANSFER_H
#define APLIKACJABANKOWA_TRANSFER_H


#include "../User/User.h"

class Transfer {
private:
    float value;
    string from;
    string to;
    string msg;
    //? nie wiem w sumie jak datę ogarnąc narazie
    string CreatedAt;
    float balanceBefore;
    float balanceAfter;
    int _id;

    void generateID() {
        int lines{};
        string line;
        fstream file;
        file.open("Transfers.txt", ios::in);
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


    friend bool createAndSaveTransfer(User &user, Transfer transfer) {
        fstream file;
        file.open("Transfers.txt", ios::out | ios::app);
        transfer.generateID();
        if (file.is_open()) {
            file << transfer._id << " "
                 << user.email + " " + transfer.to + " " + transfer.msg + " " + to_string(transfer.value);
            file << +" " + transfer.CreatedAt << user.balance << " " << user.balance - transfer.value
                 << "\n";
            file.close();
            user.balance -= transfer.value;
            user.save();

            User *receiver = User::findUserByEmail(transfer.to);
            receiver->balance += transfer.value;
            receiver->save();

            return true;
        } else
            return false;
    }
};


#endif //APLIKACJABANKOWA_TRANSFER_H
