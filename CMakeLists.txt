cmake_minimum_required(VERSION 3.21)
project(AplikacjaBankowa)

set(CMAKE_CXX_STANDARD 23)

add_executable(AplikacjaBankowa main.cpp src/classes/User/User.cpp src/classes/User/User.h src/views/Login/Login.cpp src/views/Login/Login.h src/views/View.cpp src/views/View.h src/App.cpp src/App.h src/utils/common.cpp src/utils/common.h src/views/Dashboard/Dashboard.cpp src/views/Dashboard/Dashboard.h)
