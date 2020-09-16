//
// Created by vincent on 9/16/20.
//
#include "MaxSubArrayPos.h"

using namespace std;

const std::vector<int> max_sub_array_naive_sol(const int inputs[], const int &size_array, const int &size_sub_array)
{
    vector<int> max_values;
    max_values.reserve(size_array - size_sub_array + 1);
    for (int i = 0; i <= size_array - size_sub_array; i++) {
        int max_value = inputs[i];
        for (int j = 1; j < size_sub_array; j++) {
            if (max_value < inputs[i + j]) {
                max_value = inputs[i + j];
            }
        }
        max_values.push_back(max_value);
    }

    return max_values;
}

const std::vector<int> max_sub_array_bbst_sol(const int input[], const int &size_array, const int &size_sub_array)
{

}
