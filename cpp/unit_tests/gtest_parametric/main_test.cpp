#include <gtest/gtest.h> // Dodanie biblioteki Google Test, która umożliwia pisanie i uruchamianie testów jednostkowych w C++.
#include "functions.cpp" // Dołączenie pliku z funkcjami, które będą testowane. Zakładamy, że plik ten zawiera funkcję `suma()`.

#include <tuple> // Dodanie biblioteki <tuple>, która umożliwia tworzenie krotek (tuples), co pozwala na grupowanie wielu wartości w jednej zmiennej.

// Klasa do przechowywania zestawów parametrów
// Dziedziczymy po klasie `testing::TestWithParam`, aby umożliwić przekazywanie parametrów do testów.
// Parametry w tym przypadku to krotka (tuple) trzech liczb całkowitych: dwie liczby wejściowe i oczekiwany wynik.
class AddTest : public testing::TestWithParam<std::tuple<int, int, int>> {};

// Definicja zestawów parametrów
// Funkcja `INSTANTIATE_TEST_CASE_P` służy do tworzenia testów parametrycznych.
// Podajemy nazwę testu ("ParametrizedTest"), klasę testową (`AddTest`) oraz zestawy parametrów.
// W tym przypadku tworzymy kilka krotek za pomocą `std::make_tuple`, gdzie:
// - (1, 2, 3): suma 1 i 2 powinna dać 3,
// - (-1, 1, 0): suma -1 i 1 powinna dać 0,
// - (0, 0, 0): suma 0 i 0 powinna dać 0.
INSTANTIATE_TEST_CASE_P(ParametrizedTest, AddTest,
                        testing::Values(
                            std::make_tuple(1, 2, 3),
                            std::make_tuple(-1, 1, 0),
                            std::make_tuple(0, 0, 0)
                        ));

// Test parametryczny
// Definiujemy test parametryczny `TEST_P`, który będzie wywoływany dla każdego zestawu parametrów.
// `GetParam()` pobiera bieżący zestaw parametrów (krotkę).
// Pobieramy odpowiednio pierwszy element krotki (`a`), drugi element (`b`) oraz oczekiwaną sumę (`expected_sum`).
// Następnie sprawdzamy, czy wynik funkcji `suma(a, b)` jest równy oczekiwanej sumie (`expected_sum`) za pomocą makra `EXPECT_EQ`.
TEST_P(AddTest, AddsNumbers) {
    int a = std::get<0>(GetParam()); // Pobranie pierwszej wartości z krotki (pierwsza liczba do dodania).
    int b = std::get<1>(GetParam()); // Pobranie drugiej wartości z krotki (druga liczba do dodania).
    int expected_sum = std::get<2>(GetParam()); // Pobranie trzeciej wartości z krotki (oczekiwany wynik sumy).

    EXPECT_EQ(suma(a, b), expected_sum); // Porównanie wyniku funkcji `suma(a, b)` z oczekiwaną sumą.
}

// Uruchomienie testów
// Funkcja `main` inicjuje framework Google Test i uruchamia wszystkie testy zdefiniowane w programie.
// `RUN_ALL_TESTS()` uruchamia wszystkie testy i zwraca wynik (0, jeśli wszystkie testy zakończyły się sukcesem).
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv); // Inicjalizacja Google Test z przekazaniem argumentów.
    return RUN_ALL_TESTS(); // Uruchomienie wszystkich testów i zwrócenie wyniku.
}

