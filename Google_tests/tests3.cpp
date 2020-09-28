#include "gtest/gtest.h"
#include <vector>
#include <fstream>

template <class T>
struct input_output_test: public ::testing::Test {};
typedef ::testing::Types<float, std::string, std::ofstream*> MyTypes;
TYPED_TEST_CASE(input_output_test, MyTypes);

TYPED_TEST(input_output_test, hy) {
    std::vector<TypeParam> vector;
    TypeParam typeParam;
    vector.push_back(typeParam);
    EXPECT_EQ(vector.at(0), typeParam);
}

