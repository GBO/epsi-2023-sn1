cmake_minimum_required(VERSION 3.24)
project(jegard_ly_projet)

set(CMAKE_CXX_STANDARD 17)

add_executable(jegard_ly_projet main.cpp carte.cpp carte.h paquet.cpp paquet.h bataille.cpp bataille.h morpion.h)
