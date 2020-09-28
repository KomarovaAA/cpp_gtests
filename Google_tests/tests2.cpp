#include "gtest/gtest.h"
#include <vector>

template <typename T>
struct Erase_params {
    std::initializer_list<T> elements;
    size_t start_index;
    size_t end_index;
    std::initializer_list<T> result;

};


class Erase_test: public ::testing::TestWithParam<Erase_params<float>> {};

TEST_P(Erase_test, erase) {
    Erase_params<float> params = GetParam();
    std::vector<float> vector({params.elements.begin(), params.elements.end()});
    vector.erase(vector.begin() + params.start_index, vector.begin() + params.end_index);
    EXPECT_EQ(vector.size(), params.result.size());
    std::vector<float> result(params.result.begin(), params.result.end());
    EXPECT_EQ(vector, result);
}

std::initializer_list<float> elements1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::initializer_list<float> elements2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::initializer_list<float> result1 = {1, 2, 6, 7, 8, 9};
std::initializer_list<float> result2 = {4, 5, 6, 7, 8, 9};

INSTANTIATE_TEST_CASE_P(
        erase,
        Erase_test,
        ::testing::Values(
                Erase_params<float>{
                    elements1,
                    2,
                    5,
                    result1
                },
                Erase_params<float>{
                    elements2,
                    0,
                    3,
                    result2
                }

                )
        );



