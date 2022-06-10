//
// Created by Michał Bober on 10.06.2022.
//
#include "adminDashboard.h"

void adminDashboard::userData()
{
    int num;
    cout<<"Lista uzytkownikow banku: "<<endl;
    fstream file;
    int id;
    string email,password,name,secondname,balance;
    file.open("baza_uzytkownikow.txt",ios::in);
    if(file.is_open())
    {
        while(!file.eof())
        {
            file >> id >> email >> password >> name >> secondname;
            cout<<"id = "<<id<<", E-mail = "<<email<<", Password = "<<password
            <<", Name = "<<name<<", Second Name = "<<secondname<<endl;
        }
        file.close();
    }
    else{
        cout<<"Nie udalo sie wczytac listy uzytkownikow"<<endl;
    }
    cout<<"1 aby wyjsc do poprzedniego ekranu"<<endl;
    do
    {
        num=inputNum();
    }while(num!=1);


}

void adminDashboard::transferData()
{
    fstream file;
    int id;
    string line;
    float value,balanceBefore,balanceAfter;
    string from,to,msg,date;
    file.open("Transfers.txt",ios::in);
    if(file.is_open())
    {
        while(getline(file,line))
        {
            //bartek prosze spojrz o co chodzi
            string *arrayOfStrings = splitString(line, ";", 7);
            id=stoi(arrayOfStrings[0]);
            from=arrayOfStrings[1];
            to=arrayOfStrings[2];
            value=stof(arrayOfStrings[3]);
            balanceBefore=stof(arrayOfStrings[4]);
            balanceAfter=stof(arrayOfStrings[5]);
            date=arrayOfStrings[6];
            cout<<"id: "<<id<<", od: "<<from<<", do: "<<to
                <<", opis: "<<msg<<", kwota: "<<value<<", saldo przed: "<<balanceBefore
                <<", saldo po: "<<balanceAfter<<", data: "<<date<<endl;
        }
        file.close();
    }
    else{
        cout<<"Nie udalo sie wczytac listy uzytkownikow"<<endl;
    }
    Clear();
    int num;
    cout<<"1 aby wyjsc do poprzedniego ekranu"<<endl;
    do
    {
        num=inputNum();
    }while(num!=1);
}

void adminDashboard::render()
{
    int num;
    cout<<"Witaj admin\nCo chciałbys sprawdzic"<<endl;
    cout<<"1. Lista uzytkownikow"<<endl;
    cout<<"2. Lista przelewow"<<endl;//zalezy jak bedzie wygladalo spisywanie przelewow
    num=inputNum();
    if(num==1)
    {
        userData();
    }
    else if(num==2)
    {
        transferData();
    }
}

adminDashboard::adminDashboard() {

}