//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>
#include "../core/MonkeyAndBamboo.h"
#include "../Utils.cpp"
#include "TestTool.cpp"

using namespace std;
using namespace cpstl;

void TEST_CASE_ONE()
{
    vector<int> inputs = {1, 6, 7, 11, 13};
    auto maximum_house = estimate_dimension_k<int, int>(inputs);
    string result = "Case 1: " + to_string(maximum_house);
    assert_equal<string>("TEST_CASE_ONE", "Case 1: 5", result);
}

void TEST_CASE_TWO()
{
    vector<int> inputs = {3, 9, 10, 14};
    auto maximum_house = estimate_dimension_k<int, int>(inputs);
    string result = "Case 1: " + to_string(maximum_house);
    assert_equal<string>("TEST_CASE_TWO", "Case 1: 6", result);
}

int main()
{
    TEST_CASE_ONE();
    TEST_CASE_TWO();

    return EXIT_SUCCESS;
}