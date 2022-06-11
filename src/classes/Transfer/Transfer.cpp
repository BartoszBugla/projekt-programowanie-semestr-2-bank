//
// Created by bartosz bugla on 03/06/2022.
//

#include "Transfer.h"
//int dlugosc=date.length();
//date.replace(0,dlugosc,date);
void Transfer::changeBalance(User &user,Transfer transfer) {
    //zmienne
    string line;
    fstream file;
    fstream filetemp;
    int temp;
    int id;
    string mail;
    string password;
    string name,secondName;
    float balance;



    file.open("baza_uzytkownikow.txt", ios::in);
    filetemp.open("bazatemp.txt", ios::out | ios::app);
    if(file.is_open())
    {
        if(filetemp.is_open())
        {
            while(getline(file,line)) {
                string *arrayOfStrings = splitString(line, " ", 6);
                id = stoi(arrayOfStrings[0]);
                mail = arrayOfStrings[1];
                password = arrayOfStrings[2];
                name = arrayOfStrings[3];
                secondName = arrayOfStrings[4];
                balance = stof(arrayOfStrings[5]);
                if (mail == user.email) {
                    balance = balance - transfer.value;
                }
                if (mail == transfer.to) {
                    balance = balance + transfer.value;
                }
                filetemp << id;
                filetemp << " " + mail + " " + password + " " + name + " " + secondName + " "
                         << balance << "\n";
            }
        }
        else
            cout<<"blad"<<endl;
        file.close();
    }
    else
        cout<<"blad"<<endl;
    filetemp.close();

    remove("baza_uzytkownikow.txt");
    rename("bazatemp.txt", "baza_uzytkownikow.txt");

}
