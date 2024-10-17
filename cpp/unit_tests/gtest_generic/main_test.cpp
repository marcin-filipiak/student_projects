#include "gtest/gtest.h"

// Generyczna funkcja do dodawania dwóch elementów
template <typename T>
T Add(T a, T b) {
    return a + b;
}

// Klasa testująca, parametryzowana różnymi typami danych
template <typename T>
class AddTest : public testing::Test {};

// Lista typów, które będą testowane
typedef testing::Types<int, float, double> MyTypes;

// Makro dla starszych wersji Google Test
TYPED_TEST_CASE(AddTest, MyTypes);

// Generyczny test
TYPED_TEST(AddTest, AddsNumbers) {
    TypeParam a = 5;
    TypeParam b = 10;
    TypeParam expected_sum = 15;

    EXPECT_EQ(Add(a, b), expected_sum);
}

// Uruchomienie testów
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

