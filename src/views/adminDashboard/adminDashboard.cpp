//
// Created by Michał Bober on 10.06.2022.
//
#include "adminDashboard.h"


void adminDashboard::userData() {
    User *users = User::getUsers();
    int i = 0;
    while (users[i].getid()) {
        cout << color("id: ", Color::green) << users[i].getid() << endl;
        cout << color("email: ", Color::green) + users[i].email << endl;
        cout << color("imie: ", Color::green) + users[i].name << endl;
        cout << color("nazwisko: ", Color::green) + users[i].secondName << endl;

        for (int j = 0; j < 40; j++)
            cout << color("*", Color::magenta);
        cout << endl;
        i++;
    }
}

//    int num;
//    cout << "Lista uzytkownikow banku: " << endl;
//    fstream file;
//    int id;
//    string email, password, name, secondname, balance;
//    file.open("baza_uzytkownikow.txt", ios::in);
//    if (file.is_open()) {
//        while (!file.eof()) {
//            file >> id >> email >> password >> name >> secondname;
//            cout << "id = " << id << ", E-mail = " << email << ", Password = " << password
//                 << ", Name = " << name << ", Second Name = " << secondname << endl;
//        }
//        file.close();
//    } else {
//        cout << "Nie udalo sie wczytac listy uzytkownikow" << endl;
//    }
//    cout << "1 aby wyjsc do poprzedniego ekranu" << endl;
//    do {
//        num = inputNum();
//    } while (num != 1);

//void adminDashboard::userData()
//{
//    int num;
//    cout<<"Lista uzytkownikow banku: "<<endl;
//    fstream file;
//    int id;
//    string email,password,name,secondname,balance;
//    file.open("baza_uzytkownikow.txt",ios::in);
//    if(file.is_open())
//    {
//        while(!file.eof())
//        {
//            file >> id >> email >> password >> name >> secondname >> balance;
//            cout<<"id = "<<id<<", E-mail = "<<email<<", Password = "<<password
//            <<", Name = "<<name<<", Second Name = "<<secondname<<"stan konta: "
//            <<balance<<endl;
//        }
//        file.close();
//    }
//    else{
//        cout<<"Nie udalo sie wczytac listy uzytkownikow"<<endl;
//    }
//    cout<<"1 aby wyjsc do poprzedniego ekranu"<<endl;
//    do
//    {
//        num=inputNum();
//    }while(num!=1);
//
//
//
//}

void adminDashboard::transferData() {
    cout << color("Lista przelewow\n", Color::magenta);
    for (int i = 0; i < 40; i++)
        cout << color("*", Color::magenta);
    cout << endl;
    fstream file;
    int id;
    string line;

    float value, balanceBefore, balanceAfter;
    string from, to, msg, date;

    file.open("Transfers.txt", ios::in);
    cout << color("Lista przelewow\n", Color::magenta);
    for (int i = 0; i < 40; i++)
        cout << color("*", Color::magenta);
    cout << endl;


    if (file.is_open()) {
        while (getline(file, line)) {

            float value, balanceBefore, balanceAfter;
            string from, to, msg, date;
            file.open("Transfers.txt", ios::in);
            if (file.is_open()) {
                while (getline(file, line)) {


                    string *arrayOfStrings = splitString(line, ";", 8);
                    id = stoi(arrayOfStrings[0]);
                    from = arrayOfStrings[1];
                    to = arrayOfStrings[2];
                    msg = arrayOfStrings[3];
                    value = stof(arrayOfStrings[4]);
                    balanceBefore = stof(arrayOfStrings[5]);
                    balanceAfter = stof(arrayOfStrings[6]);
                    date = arrayOfStrings[7];
                    cout << color("id: ", Color::green) << id;
                    cout << color(", od: ", Color::green) + from;
                    cout << color(", do: ", Color::green) + to;
                    cout << color(", wiadomosc: ", Color::green) + msg << endl;
                    cout << color("kwota: ", Color::green) << value;
                    cout << color(", saldo przed: ", Color::green) << balanceBefore;
                    cout << color(", saldo po: ", Color::green) << balanceAfter;
                    cout << color(", data: ", Color::green) + date << endl;
                    for (int i = 0; i < 40; i++)
                        cout << color("*", Color::magenta);
                    cout << endl;
                }
                file.close();
            } else {
                cout << "Nie udalo sie wczytac listy uzytkownikow" << endl;
            }
            Clear();
            int num;
            cout << "1 aby wyjsc do poprzedniego ekranu" << endl;
            do {
                num = inputNum();
            } while (num != 1);
        }
    }
}

void adminDashboard::render() {
    int num;
    cout << "Witaj" << color(" ADMIN", Color::red) << endl;
    for (int i = 0; i < 40; i++)
        cout << color("*", Color::magenta);
    cout << "\n1. Lista uzytkownikow" << endl;
    cout << "2. Lista przelewow" << endl;//zalezy jak bedzie wygladalo spisywanie przelewow
    cout << "3. Wyloguj sie" << endl;
    for (int i = 0; i < 40; i++)
        cout << color("*", Color::magenta);
    cout << endl;
    num = inputNum();
    if (num == 1) {
        userData();
    } else if (num == 2) {
        transferData();
    } else if (num == 3) {
        setScreen(welcomeScreen);
    }
}
