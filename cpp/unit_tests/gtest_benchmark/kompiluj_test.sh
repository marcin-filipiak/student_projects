#!/bin/sh
rm main_test
clear
echo "----Kompilacja benchmarka testujacego----"

g++ -std=c++11 main_test.cpp -o main_test  -lbenchmark -lpthread

echo "---Kompilacja benchmarka ukonczona----"
echo "---Uruchamianie beanchmarka---"
chmod +x main_test
./main_test
echo "---Zakonczono benchmark---"
