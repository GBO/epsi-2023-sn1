cmake_minimum_required(VERSION 3.24)
project(unt)

set(CMAKE_CXX_STANDARD 17)

add_executable(unt main.cpp tree.hpp tree.cpp inventory.cpp inventory.hpp zone.cpp item.cpp player.cpp)
