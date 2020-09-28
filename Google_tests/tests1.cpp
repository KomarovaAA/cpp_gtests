#include "gtest/gtest.h"
#include <vector>

TEST(vector, push_back) {
    std::vector<float> x;
    x.push_back(10);
    EXPECT_EQ(10u, x.at(0));

}

TEST(vector, pop_back) {
    std::vector<float> x;
    for (int i = 0; i < 10; i++) {
        x.push_back(i);
    }
    for (int i = 9; i >= 0; i--) {
        EXPECT_EQ(i, x.back());
        x.pop_back();
    }
}

TEST(vector, erase){
    std::vector<float> x;
    for (int i = 0; i < 10; i++) {
        x.push_back(i);
    }
    x.erase(x.begin());
    EXPECT_EQ(1u, x.at(0));
    EXPECT_EQ(9u, x.size());
    x.erase(x.begin(), x.end());
    EXPECT_EQ(0, x.size());
}

TEST(vector, begin) {
    std::vector<float> x;
    for (int i = 0; i < 10; i++) {
        x.push_back(i);
    }
    EXPECT_EQ(0u, *x.begin());
    x.erase(x.begin());
    EXPECT_EQ(1u, *x.begin());
}

TEST(vector, end) {
    std::vector<float> x;
    for (int i = 0; i < 10; i++) {
        x.push_back(i);
    }
    EXPECT_EQ(9u, *(--x.end()));
    x.erase(--x.end());
    EXPECT_EQ(8u, *(--x.end()));
}

TEST(vector, size) {
    std::vector<float> x;
    EXPECT_EQ(0u, x.size());
    for (int i = 0; i < 10; i++) {
        x.push_back(i);
    }
    EXPECT_EQ(10u, x.size());
}

TEST(vector, constructor_copy) {
    std::vector<float> x;
    for (int i = 0; i < 10; i++) {
        x.push_back(i);
    }
    std::vector<float> y(x);
    EXPECT_EQ(x, y);

}

TEST(vector, constructor_remove) {
    std::vector<float> y(std::vector<float>({10, 220, 10}));
    EXPECT_EQ(3u, y.size());
    EXPECT_EQ(10, y.at(0));
    EXPECT_EQ(220u, y.at(1));
    EXPECT_EQ(10u, y.at(2));
}

TEST(vector, operator_copy){
    std::vector<float> x({10, 220, 10});
    std::vector<float> y = x;
    EXPECT_EQ(x, y);
}

TEST(vector, operator_remove){
    std::vector<float> y = std::vector<float>({10, 220, 10});
    EXPECT_EQ(3u, y.size());
    EXPECT_EQ(10, y.at(0));
    EXPECT_EQ(220u, y.at(1));
    EXPECT_EQ(10u, y.at(2));

}