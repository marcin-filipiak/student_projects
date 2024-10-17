// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"

////grupa testów "SumaTest"
TEST(SumaTest, DodawanieLiczbCalkowitych) {
    int wynik = suma(5, 1);
    EXPECT_EQ(wynik, 6); // Sprawdza, czy wynik jest równy 6, ale nie kończy testu w przypadku niepowodzenia
}

////grupa testów "AssertionsTest" które pokazują inne asercje z google test
TEST(AssertionsTest, Equality) {
    int a = 5;
    int b = 5;
    EXPECT_EQ(a, b); // Sprawdza, czy a jest równe b, ale nie kończy testu w przypadku niepowodzenia
    //ASSERT_EQ(a, b); // Sprawdza, czy a jest równe b i kończy test, jeśli nie jest
}

TEST(AssertionsTest, Inequality) {
    int a = 5;
    int b = 10;
    EXPECT_NE(a, b); // Sprawdza, czy a nie jest równe b, ale nie kończy testu w przypadku niepowodzenia
    //ASSERT_NE(a, b); // Sprawdza, czy a nie jest równe b i kończy test, jeśli jest
}

TEST(AssertionsTest, TrueCondition) {
    bool condition = true;
    EXPECT_TRUE(condition); // Sprawdza, czy warunek jest prawdziwy, ale nie kończy testu w przypadku niepowodzenia
    //ASSERT_TRUE(condition); // Sprawdza, czy warunek jest prawdziwy i kończy test, jeśli nie jest
}

TEST(AssertionsTest, FalseCondition) {
    bool condition = false;
    EXPECT_FALSE(condition); // Sprawdza, czy warunek jest fałszywy, ale nie kończy testu w przypadku niepowodzenia
    //ASSERT_FALSE(condition); // Sprawdza, czy warunek jest fałszywy i kończy test, jeśli nie jest
}

TEST(AssertionsTest, GreaterThan) {
    int a = 10;
    int b = 5;
    EXPECT_GT(a, b); // Sprawdza, czy a jest większe niż b, ale nie kończy testu w przypadku niepowodzenia
    ASSERT_GT(a, b); // Sprawdza, czy a jest większe niż b i kończy test, jeśli nie jest
}


// ... inne testy ...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

