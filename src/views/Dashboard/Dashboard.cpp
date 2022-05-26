//
// Created by bartosz bugla on 26/05/2022.
//

#include "Dashboard.h"


void Dashboard::render(){
    Clear();
    cout << "cześć"<< View::user->name<<endl;
    cout <<"Wcisnij 3 aby wyjśc, 1 do loginu"<<endl;
    View::screen = stoi(input());
}