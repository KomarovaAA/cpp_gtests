#include <vector>
#include <iostream>
#include <gtest/gtest.h>

TEST(vector, size){
    std::vector<float> x;
    EXPECT_EQ(0u, x.size());
    x.push_back(1);
    EXPECT_EQ(1u, x.size())

}

