//
// Created by bartosz bugla on 24/05/2022.
//

#include "App.h"

App::App(){
    //inicjalizja globalnych zmiennych w sumie można to gdzieś przenieść
    //co myślicie?
    View::user = new User();
    View::screen = login;
    Login loginScreen = Login();
    Dashboard dashboardScreen = Dashboard();

    User uzytkownik;
//    uzytkownik.reg();
    //odkomentowac zeby sprawdzic dzialanie rejestracji
    //Starajmy się tu trzymać jak najmniej używania czegokolwiek
    //logiki itd najlepiej tu trzymać tylko poszczególne widoki
    //ewentualnie jakiś globalne rzeczy
    //ale globalne też możmna w klasie view


     while(true){
         switch(View::screen){
             case Screen::login:
                 loginScreen.render();
                continue;
             case Screen::dashboard:
                 dashboardScreen.render();
                 continue;
             case Screen::leave:
                 //exit
                 break;
             default:
                 cout<<"podaj ekran na który chcesz przejść 404"<<endl;
                 //jak sie poda stringa to sie wypieroli trzeba to potem zabezpieczyć
                 int correct =false;
                 while(!correct){
                     try{
                         int nextScreen = inputNum();
                         View::setScreen<int>(nextScreen);
                         correct = true;
                     }catch(string err){
                         correct=false;
                         cout<<err<<endl;
                     }
                 }



                 continue;
         }
         break;
     }
}