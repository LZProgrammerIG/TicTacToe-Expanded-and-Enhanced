cmake_minimum_required(VERSION 3.14)

project(tictactoe VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQURIED ON)

set(CMAKE_AUTO_MOC TRUE)
set(CMAKE_AUTORCC TRUE)
set(CMAKE_AUTOUIC TRUE)

find_package(Qt6 REQUIRED COMPONENTS 
    Core 
    Gui 
    Widgets
)

add_subdirectory(src)