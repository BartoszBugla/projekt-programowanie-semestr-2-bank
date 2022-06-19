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
    time_t now = time(0);
    string CreatedAt = ctime(&now);
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


    void changeBalance(User &user, Transfer transfer);

//
    bool save(const User &user) {
        fstream file;
        file.open("Transfers.txt", ios::out | ios::app);
        this->generateID();
        if (file.is_open()) {
            file << this->_id << ";"
                 << user.email + ";" + this->to + ";" + this->msg + ";" + to_string(this->value);
            file << +";" << user.balance << ";" << user.balance - this->value << +";" + this->CreatedAt;
            file.close();
        }
        return true;
    }

    friend bool createAndSaveTransfer(User &user, Transfer transfer) {
        //transfer
        transfer.save(user);
        // sender
        user.balance -= transfer.value;
        user.save();

        //receiver
        User *receiver = User::findUserByEmail(transfer.to);
        receiver->balance += transfer.value;
        receiver->save();
        return true;
    }
};

#endif //APLIKACJABANKOWA_TRANSFER_H
