cmake_minimum_required(VERSION 3.21)
project(AplikacjaBankowa)

set(CMAKE_CXX_STANDARD 17)

add_executable(AplikacjaBankowa main.cpp src/classes/User/User.cpp src/classes/User/User.h src/views/Login/Login.cpp src/views/Login/Login.h src/views/View.cpp src/views/View.h src/App.cpp src/App.h src/utils/common.cpp src/utils/common.h src/views/Dashboard/Dashboard.cpp src/views/Dashboard/Dashboard.h src/classes/blik.cpp src/classes/blik.h src/views/Register/Register.cpp src/views/Register/Register.h src/views/Profile/Profile.cpp src/views/Profile/Profile.h src/classes/Transfer/Transfer.cpp src/classes/Transfer/Transfer.h src/views/CreateTransfer/CreateTransfer.cpp src/views/CreateTransfer/CreateTransfer.h src/views/adminDashboard/adminDashboard.cpp src/views/adminDashboard/adminDashboard.h src/views/transferHistory/transferHistory.cpp src/views/transferHistory/transferHistory.h)
