//
// Created by bartosz bugla on 24/05/2022.
//

#include "App.h"

App::App() {
    View::user = new User();
    View::screen = login;
    Dashboard dashboardScreen = Dashboard();
    Profile profileScreen = Profile();
    CreateTransfer createTransferScreen = CreateTransfer();
    adminDashboard adminDashboardScreen = adminDashboard();
    transferHistory transferHistoryScreen = transferHistory();
    Login loginScreen = Login();
    Register registerScreen = Register();

    while (true) {
        switch (View::screen) {
            case Screen::createTransferScreen:
                createTransferScreen.render();
                continue;
            case Screen::login:
                loginScreen.render();
                continue;
            case Screen::dashboard:
                dashboardScreen.render();
                continue;
            case Screen::reg:
                registerScreen.render();
                continue;
            case Screen::profile:
                profileScreen.render();
                continue;
            case Screen::AdminDashboard:
                adminDashboardScreen.render();
                continue;
            case Screen::welcomeScreen:
                dashboardScreen.welcomeScreen();
                continue;
            case Screen::TransferHistory:
                transferHistoryScreen.render();
                continue;
            case Screen::leave:
                //exit
                break;
            default:
                cout << "podaj ekran na który chcesz przejść 404" << endl;
                //jak sie poda stringa to sie wypieroli trzeba to potem zabezpieczyć
                int correct = false;
                while (!correct) {
                    try {
                        int nextScreen = inputNum();
                        View::setScreen<int>(nextScreen);
                        correct = true;
                    } catch (string err) {
                        correct = false;
                        cout << err << endl;
                    }
                }


                continue;
        }
        break;
    }
}