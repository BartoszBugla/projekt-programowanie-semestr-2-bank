//
// Created by bartosz bugla on 24/05/2022.
//

#include "App.h"

App::App(){
    View::user = new User();
    View::screen = 1;
    View::user->email = "bartek";

    Login loginScreen = Login();
    Dashboard dashboardScreen = Dashboard();

     while(true){
         switch(View::screen){
             case 1:
                 loginScreen.render();
                continue;
             case 2:
                 dashboardScreen.render();
                 //robocze

                 continue;
             case 3:
                 break;
             default:
                 cout<<"podaj ekran na który chcesz przejść 404"<<endl;
                 cin>> View::screen;
                 continue;
         }
         break;
     }
}