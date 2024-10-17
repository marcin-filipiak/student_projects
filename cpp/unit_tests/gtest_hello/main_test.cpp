// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"

TEST(SumaTest, DodawanieLiczbCalkowitych) {
    int wynik = suma(5, 1);
    EXPECT_EQ(wynik, 6);
}

// ... inne testy ...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

