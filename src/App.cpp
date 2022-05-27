//
// Created by bartosz bugla on 24/05/2022.
//

#include "App.h"

App::App(){
    //inicjalizja globalnych zmiennych w sumie można to gdzieś przenieść
    //co myślicie?
    View::user = new User();
    View::screen = 1;
    Login loginScreen = Login();
    Dashboard dashboardScreen = Dashboard();

    User uzytkownik;
    //uzytkownik.reg();
    //odkomentowac zeby sprawdzic dzialanie rejestracji
    //Starajmy się tu trzymać jak najmniej używania czegokolwiek
    //logiki itd najlepiej tu trzymać tylko poszczególne widoki
    //ewentualnie jakiś globalne rzeczy
    //ale globalne też możmna w klasie view


     while(true){
         switch(View::screen){
             case 1:
                 loginScreen.render();
                continue;
             case 2:
                 dashboardScreen.render();
                 continue;
             case 3:
                 //exit
                 break;
             default:
                 cout<<"podaj ekran na który chcesz przejść 404"<<endl;
                 //jak sie poda stringa to sie wypieroli trzeba to potem zabezpieczyć
                  View::screen = stoi(input())
                 continue;
         }
         break;
     }
}