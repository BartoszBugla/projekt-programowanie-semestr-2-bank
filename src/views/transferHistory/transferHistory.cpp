//
// Created by Michał Bober on 12.06.2022.
//

#include "transferHistory.h"

void transferHistory::getHistory(User &user) {
    fstream file,filetemp,filetemp2;
    int id;
    string line;
    float value,balanceBefore,balanceAfter;
    string from,to,msg,date;
    bool valid=false;
    cout<<color("HISTORIA PRZELEWOW",Color::magenta)<<endl;
    cout<<color("ZIELONE - Przychodzace, ",Color::green)<<color("CZERWONE - Wychodzace",Color::red)<<endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout<<endl;
        file.open("Transfers.txt", ios::in);
        filetemp.open("TransfersCopy.txt", ios::out);
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
                if (from == user.email) {
                    cout << color("do: ", Color::red) + to;
                    cout << color(", kwota: ", Color::red) << value << endl;
                    cout << color("wiadomosc: ", Color::red) + msg;
                    cout << color(", data: ", Color::red) + date << endl;
                    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                    filetemp << id << ";" << from << ";" << to << ";" << msg << ";" << value << ";" << balanceBefore
                             << ";" << balanceAfter << ";" << date << endl;
                    cout << endl;
                } else if (to == user.email) {
                    cout << color("od: ", Color::green) + from;
                    cout << color(", kwota: ", Color::green) << value << endl;
                    cout << color("wiadomosc: ", Color::green) + msg;
                    cout << color(", data: ", Color::green) + date << endl;
                    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                    filetemp << id << ";" << from << ";" << to << ";" << msg << ";" << value << ";" << balanceBefore
                             << ";" << balanceAfter << ";" << date << endl;
                    cout << endl;
                }
            }
            file.close();
            filetemp.close();
        } else {
            cout << "Nie udalo sie wczytac listy uzytkownikow" << endl;
        }
    int num;
    cout<<"\n1) Wyjscie do ekranu glownego"<<endl;
    cout<<"2) Menu sortowania" << endl;
    cout<<"3) Ekran profilu"<<endl;
    cout << "Dokonaj wyboru:";
    int wybor,set;
    string opisSort;
    do{
        valid=false;
        cin >> set;
        if (cin.good() && set>0 && set<4){
            valid = true;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Podaj liczbe z zakresu od 1 do 3." << endl;
        }
    } while (!valid);
    if(set==3)
        setScreen(profile);
    else if(set==2) {
        do {
            cout << "==============" << endl;
            cout << "1) Wzgledem kwoty" << endl;
            cout << "2) Wychodzace" << endl;
            cout << "3) Przychodzace" << endl;
            cout << "4) Opis" << endl;
            cout << "5) Osoba" << endl;
            cout << "6) Aby wyczyscic filtry " << endl;
            cout << "7) Aby wejsc do menu" << endl;
            cout << "Dokonaj wyboru: ";
            do {
                valid = false;
                cin >> wybor;
                if (cin.good() && wybor > 0 && wybor < 8) {
                    valid = true;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Podaj liczbe z zakresu od 1 do 9." << endl;
                }
            } while (!valid);

            switch (wybor) {
                case 1:
                    int doKwota, odKwota;
                    do {
                        valid = false;
                        cout << "Podaj kwote od: ";
                        cin >> odKwota;
                        cout << "Podaj kwote do: ";
                        cin >> doKwota;
                        if (cin.good() && odKwota <= doKwota) {
                            valid = true;
                        } else {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Podaj poprawne dane." << endl;
                        }
                    } while (!valid);

                    system("cls");
                    filetemp.open("TransfersCopy.txt", ios::in);
                    filetemp2.open("TransfersCopy2.txt", ios::out);
                    if (filetemp.is_open()) {
                        while (getline(filetemp, line)) {
                            string *arrayOfStrings = splitString(line, ";", 8);
                            id = stoi(arrayOfStrings[0]);
                            from = arrayOfStrings[1];
                            to = arrayOfStrings[2];
                            msg = arrayOfStrings[3];
                            value = stof(arrayOfStrings[4]);
                            balanceBefore = stof(arrayOfStrings[5]);
                            balanceAfter = stof(arrayOfStrings[6]);
                            date = arrayOfStrings[7];
                            if (from == user.email && value >= odKwota && value <= doKwota) {
                                cout << color("do: ", Color::red) + to;
                                cout << color(", kwota: ", Color::red) << value << endl;
                                cout << color("wiadomosc: ", Color::red) + msg;
                                cout << color(", data: ", Color::red) + date << endl;
                                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                                cout << endl;
                                filetemp2 << line << endl;
                            } else if (to == user.email && value >= odKwota && value <= doKwota) {
                                cout << color("od: ", Color::green) + from;
                                cout << color(", kwota: ", Color::green) << value << endl;
                                cout << color("wiadomosc: ", Color::green) + msg;
                                cout << color(", data: ", Color::green) + date << endl;
                                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                                filetemp2 << line << endl;
                                cout << endl;
                            }
                        }
                        filetemp.close();
                        filetemp2.close();
                    }
                    filetemp.open("TransfersCopy.txt", ios::trunc | ios::out);
                    filetemp2.open("TransfersCopy2.txt", ios::in);
                    if (filetemp2.is_open()) {
                        while (getline(filetemp2, line)) {
                            filetemp << line << endl;
                        }
                    }
                    filetemp.close();
                    filetemp2.close();
                    break;
                case 2:
                    system("cls");
                    filetemp.open("TransfersCopy.txt", ios::in);
                    filetemp2.open("TransfersCopy2.txt", ios::out);
                    if (filetemp.is_open()) {
                        while (getline(filetemp, line)) {
                            string *arrayOfStrings = splitString(line, ";", 8);
                            id = stoi(arrayOfStrings[0]);
                            from = arrayOfStrings[1];
                            to = arrayOfStrings[2];
                            msg = arrayOfStrings[3];
                            value = stof(arrayOfStrings[4]);
                            balanceBefore = stof(arrayOfStrings[5]);
                            balanceAfter = stof(arrayOfStrings[6]);
                            date = arrayOfStrings[7];
                            if (from == user.email) {
                                cout << color("do: ", Color::red) + to;
                                cout << color(", kwota: ", Color::red) << value << endl;
                                cout << color("wiadomosc: ", Color::red) + msg;
                                cout << color(", data: ", Color::red) + date << endl;
                                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                                cout << endl;
                                filetemp2 << line << endl;
                            }
                        }
                        filetemp.close();
                        filetemp2.close();
                    }
                    filetemp.open("TransfersCopy.txt", ios::trunc | ios::out);
                    filetemp2.open("TransfersCopy2.txt", ios::in);
                    if (filetemp2.is_open()) {
                        while (getline(filetemp2, line)) {
                            filetemp << line << endl;
                        }
                    }
                    break;
                case 3:
                    system("cls");
                    filetemp.open("TransfersCopy.txt", ios::in);
                    filetemp2.open("TransfersCopy2.txt", ios::out);
                    if (filetemp.is_open()) {
                        while (getline(filetemp, line)) {
                            string *arrayOfStrings = splitString(line, ";", 8);
                            id = stoi(arrayOfStrings[0]);
                            from = arrayOfStrings[1];
                            to = arrayOfStrings[2];
                            msg = arrayOfStrings[3];
                            value = stof(arrayOfStrings[4]);
                            balanceBefore = stof(arrayOfStrings[5]);
                            balanceAfter = stof(arrayOfStrings[6]);
                            date = arrayOfStrings[7];
                            if (to == user.email) {
                                cout << color("od: ", Color::green) + from;
                                cout << color(", kwota: ", Color::green) << value << endl;
                                cout << color("wiadomosc: ", Color::green) + msg;
                                cout << color(", data: ", Color::green) + date << endl;
                                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                                cout << endl;
                                filetemp2 << line << endl;
                            }
                        }
                        filetemp.close();
                        filetemp2.close();
                    }
                    filetemp.open("TransfersCopy.txt", ios::trunc | ios::out);
                    filetemp2.open("TransfersCopy2.txt", ios::in);
                    if (filetemp2.is_open()) {
                        while (getline(filetemp2, line)) {
                            filetemp << line << endl;
                        }
                    }
                    filetemp.close();
                    filetemp2.close();
                    break;
                case 4:
                    cout << "Podaj opis: ";
                    opisSort = input();
                    system("cls");
                    filetemp.open("TransfersCopy.txt", ios::in);
                    filetemp2.open("TransfersCopy2.txt", ios::out);
                    if (filetemp.is_open()) {
                        while (getline(filetemp, line)) {
                            string *arrayOfStrings = splitString(line, ";", 8);
                            id = stoi(arrayOfStrings[0]);
                            from = arrayOfStrings[1];
                            to = arrayOfStrings[2];
                            msg = arrayOfStrings[3];
                            value = stof(arrayOfStrings[4]);
                            balanceBefore = stof(arrayOfStrings[5]);
                            balanceAfter = stof(arrayOfStrings[6]);
                            date = arrayOfStrings[7];
                            if (from == user.email && msg == opisSort) {
                                cout << color("do: ", Color::red) + to;
                                cout << color(", kwota: ", Color::red) << value << endl;
                                cout << color("wiadomosc: ", Color::red) + msg;
                                cout << color(", data: ", Color::red) + date << endl;
                                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                                cout << endl;
                                filetemp2 << line << endl;
                            } else if (to == user.email && msg == opisSort) {
                                cout << color("od: ", Color::green) + from;
                                cout << color(", kwota: ", Color::green) << value << endl;
                                cout << color("wiadomosc: ", Color::green) + msg;
                                cout << color(", data: ", Color::green) + date << endl;
                                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                                filetemp2 << line << endl;
                                cout << endl;
                            }
                        }
                        filetemp.close();
                        filetemp2.close();
                    }
                    filetemp.open("TransfersCopy.txt", ios::trunc | ios::out);
                    filetemp2.open("TransfersCopy2.txt", ios::in);
                    if (filetemp2.is_open()) {
                        while (getline(filetemp2, line)) {
                            filetemp << line << endl;
                        }
                    }
                    filetemp.close();
                    filetemp2.close();
                    break;
                case 5:
                    cout << "Podaj nazwe osoby:";
                    cin >> opisSort;
                    system("cls");
                    filetemp.open("TransfersCopy.txt", ios::in);
                    filetemp2.open("TransfersCopy2.txt", ios::out);
                    if (filetemp.is_open()) {
                        while (getline(filetemp, line)) {
                            string *arrayOfStrings = splitString(line, ";", 8);
                            id = stoi(arrayOfStrings[0]);
                            from = arrayOfStrings[1];
                            to = arrayOfStrings[2];
                            msg = arrayOfStrings[3];
                            value = stof(arrayOfStrings[4]);
                            balanceBefore = stof(arrayOfStrings[5]);
                            balanceAfter = stof(arrayOfStrings[6]);
                            date = arrayOfStrings[7];
                            if (opisSort == to && from == user.email) {
                                cout << color("do: ", Color::red) + to;
                                cout << color(", kwota: ", Color::red) << value << endl;
                                cout << color("wiadomosc: ", Color::red) + msg;
                                cout << color(", data: ", Color::red) + date << endl;
                                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                                cout << endl;
                                filetemp2 << line << endl;
                            } else if (opisSort == from && to == user.email) {
                                cout << color("od: ", Color::green) + from;
                                cout << color(", kwota: ", Color::green) << value << endl;
                                cout << color("wiadomosc: ", Color::green) + msg;
                                cout << color(", data: ", Color::green) + date << endl;
                                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                                filetemp2 << line << endl;
                                cout << endl;
                            }
                        }
                        filetemp.close();
                        filetemp2.close();
                    }
                    filetemp.open("TransfersCopy.txt", ios::trunc | ios::out);
                    filetemp2.open("TransfersCopy2.txt", ios::in);
                    if (filetemp2.is_open()) {
                        while (getline(filetemp2, line)) {
                            filetemp << line << endl;
                        }
                    }
                    filetemp.close();
                    filetemp2.close();
                    break;
                case 6:
                    system("cls");
                    file.open("Transfers.txt", ios::in);
                    filetemp.open("TransfersCopy.txt", ios::out);
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
                            if (from == user.email) {
                                cout << color("do: ", Color::red) + to;
                                cout << color(", kwota: ", Color::red) << value << endl;
                                cout << color("wiadomosc: ", Color::red) + msg;
                                cout << color(", data: ", Color::red) + date << endl;
                                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                                filetemp << line << endl;
                                cout << endl;
                            } else if (to == user.email) {
                                cout << color("od: ", Color::green) + from;
                                cout << color(", kwota: ", Color::green) << value << endl;
                                cout << color("wiadomosc: ", Color::green) + msg;
                                cout << color(", data: ", Color::green) + date << endl;
                                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                                filetemp << line << endl;
                                cout << endl;
                            }
                        }
                        file.close();
                        filetemp.close();
                    } else {
                        cout << "Nie udalo sie wczytac listy uzytkownikow" << endl;
                    }
                    cout << "Wyczyszcono filtry." << endl;
                    break;
                default:
                    break;
            }
        } while (wybor != 7);
    }
    else if(set==1)
        setScreen(dashboard);
    return;
}


void transferHistory::render()
{
    getHistory(*View::user);
}

transferHistory::transferHistory() {
}