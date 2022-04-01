#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
vector<T> pow2(vector<T> const &input) {
    vector<T> pow2Vector(input.begin(), input.end());

    transform(input.begin(), input.end(), input.begin(), pow2Vector.begin(), multiplies<T>());

    return pow2Vector;
}

TEST(Pow2Test, Test) {
    vector<long> input = {2, 5, 10, 15, 20, 25, 30, 45, 100};
    vector<long> expected = {4, 25, 100, 225, 400, 625, 900, 2025, 10000};
    auto actual = pow2(input);

    ASSERT_EQ(expected, actual);
}

TEST(Pow2TestNegativeNumbers, Test) {
    vector<signed long> input = {-2, -5, -10, -15, -20, -25, -30, -45, -100};
    vector<signed long> expected = {4, 25, 100, 225, 400, 625, 900, 2025, 10000};
    auto actual = pow2(input);

    ASSERT_EQ(expected, actual);
}

int main(int ac, char **av) {
    ::testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}

