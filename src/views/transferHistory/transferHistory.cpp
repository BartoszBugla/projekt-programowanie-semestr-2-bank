//
// Created by Michał Bober on 12.06.2022.
//

#include "transferHistory.h"

void transferHistory::getHistory(User &user) {
    fstream file;
    int id;
    string line;
    float value,balanceBefore,balanceAfter;
    string from,to,msg,date;
    cout<<color("HISTORIA PRZELEWOW",Color::magenta)<<endl;
    cout<<color("ZIELONE - Przychodzace, ",Color::green)<<color("CZERWONE - Wychodzace",Color::red)<<endl;
    for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
    cout<<endl;
    file.open("Transfers.txt",ios::in);
    if(file.is_open())
    {
        while(getline(file,line))
        {
            string *arrayOfStrings = splitString(line,";", 8);
            id=stoi(arrayOfStrings[0]);
            from=arrayOfStrings[1];
            to=arrayOfStrings[2];
            msg=arrayOfStrings[3];
            value=stof(arrayOfStrings[4]);
            balanceBefore=stof(arrayOfStrings[5]);
            balanceAfter=stof(arrayOfStrings[6]);
            date=arrayOfStrings[7];
            if(from==user.email)
            {
                cout << color("do: ", Color::red) + to;
                cout << color(", kwota: ", Color::red) << value<<endl;
                cout << color("wiadomosc: ", Color::red) + msg;
                cout << color(", data: ", Color::red) + date << endl;
                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                cout<<endl;
            }
            else if(to==user.email)
            {
                cout << color("od: ", Color::green) + from;
                cout << color(", kwota: ", Color::green) << value<<endl;
                cout << color("wiadomosc: ", Color::green) + msg;
                cout << color(", data: ", Color::green) + date << endl;
                for (int i = 0; i < 40; i++) cout << color("*", Color::magenta);
                cout<<endl;
            }
        }
        file.close();
    }
    else{
        cout<<"Nie udalo sie wczytac listy uzytkownikow"<<endl;
    }
    int num;
    cout<<"\n1 aby wyjsc do poprzedniego ekranu"<<endl;
    do
    {
        num=inputNum();
    }while(num!=1);
    setScreen(dashboard);
    return;
}

void transferHistory::render()
{
    getHistory(*View::user);
}

transferHistory::transferHistory() {
}