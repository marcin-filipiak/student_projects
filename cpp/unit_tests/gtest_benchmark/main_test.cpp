#include "benchmark/benchmark.h"

/////////////////////////////////////////////////////
// Funkcja dodająca dwie liczby i jej benchmark

// Funkcja dodająca dwie liczby
int add(int a, int b){
	return a+b;
}

// benchmark
static void BM_Add(benchmark::State& state) {
    int a = 5;
    int b = 10;
    for (auto _ : state) {
        // Benchmarkowany kod
        int result = add(a, b);
        benchmark::DoNotOptimize(result);
    }
}

//////////////////////////////////////////////////////
//Funkcja obliczająca sumę kwadratów liczb i jej benchmark

// Prosta funkcja obliczająca sumę kwadratów liczb od 1 do n
unsigned long long calculateSumOfSquares(int n) {
    // Alokacja dynamicznej tablicy dla przechowywania kwadratów
    unsigned long long *squares = new unsigned long long[n];
    // Obliczenie kwadratów i sumy
    unsigned long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        squares[i - 1] = i * i;
        sum += squares[i - 1];
    }
    // Zwolnienie zaalokowanej pamięci
    delete[] squares;
    return sum;
}

// benchmark
static void BM_calculateSumOfSquares(benchmark::State& state) {
    for (auto _ : state) {
        // Benchmarkowany kod
        int result = calculateSumOfSquares(5);
        benchmark::DoNotOptimize(result);
    }
}

/////////////////////////////////////////////////////
//uruchomienie benchmarków

BENCHMARK(BM_Add);
BENCHMARK(BM_calculateSumOfSquares);

BENCHMARK_MAIN();

