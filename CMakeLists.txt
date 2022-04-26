cmake_minimum_required(VERSION 3.0)
project(battleship)

set(CMAKE_CXX_STANDARD 14)

add_executable(battleship 
		battleship/main.cpp battleship/field.h battleship/ship.h battleship/point.h
		battleship/attack_field.h battleship/protection_field.h battleship/player.h
		battleship/game.h
		)
