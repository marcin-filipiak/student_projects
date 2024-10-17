#!/bin/sh
rm main_test
clear
echo "----Kompilacja programu testujacego----"

# Kompilacja kodu testów
g++ main_test.cpp -o main_test -lgtest -lgtest_main -pthread

echo "---Kompilacja testow ukonczona----"
echo "---Uruchamianie programu testujacego---"
chmod +x main_test
./main_test
echo "---Zakonczono program testujacy---"
