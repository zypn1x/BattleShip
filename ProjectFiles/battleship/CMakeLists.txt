cmake_minimum_required(VERSION 3.21)
project(battleship)

set(CMAKE_CXX_STANDARD 14)

add_executable(battleship main.cpp field.h ship.h point.h attack_field.h protection_field.h player.h)
