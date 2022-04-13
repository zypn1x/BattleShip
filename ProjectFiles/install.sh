#! /bin/sh

cd ./battleship
mkdir build
cd build
cmake ..
make
mv battleship ../../run
