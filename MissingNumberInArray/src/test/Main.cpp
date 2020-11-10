//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>
#include "../core/MissingNumberInArray.h"
#include "../Utils.cpp"
#include "TestTool.cpp"

using namespace std;
using namespace cpstl;

void TEST_XOR_ONE()
{
    vector<int> inputs = {1,2,3,5};
    int number = get_missing_number_bitmagic(inputs, 5);
    assert_equal("XOR One", 4, number);
}

void TEST_XOR_TWO()
{
    vector<int> inputs = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int number = get_missing_number_bitmagic(inputs, 10);
    assert_equal("XOR two", 0, number);
}

void TEST_SUM_ONE()
{
    vector<int> inputs = {1,2,3,5};
    int number = get_missing_number_with_sum(inputs, 5);
    assert_equal("SUM One", 4, number);
}

void TEST_SUM_TWO()
{
    vector<int> inputs = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int number = get_missing_number_formula(inputs, 10);
    assert_equal("SUM two", 0, number);
}

void TEST_TOT_SUM_ONE()
{
    vector<int> inputs = {1,2,3,5};
    int number = get_missing_number_formula(inputs, 5);
    assert_equal("TOT SUM one", 4, number);
}

void TEST_TOT_SUM_TWO()
{
    vector<int> inputs = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int number = get_missing_number_with_sum(inputs, 10);
    assert_equal("TOT SUM two", 0, number);
}

int main()
{
    TEST_XOR_ONE();
    TEST_XOR_TWO();
    TEST_SUM_ONE();
    TEST_SUM_TWO();
    TEST_TOT_SUM_ONE();
    TEST_TOT_SUM_TWO();
    return EXIT_SUCCESS;
}