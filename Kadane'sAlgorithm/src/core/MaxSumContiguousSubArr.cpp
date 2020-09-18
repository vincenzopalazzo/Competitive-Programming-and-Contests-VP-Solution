//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include "MaxSumContiguousSubArr.h"

using namespace std;

int sum_contiguous_sub_arr(const std::vector<int> &input)
{
    int max_elem = INT32_MIN;
    int max_tmp = 0;
    for (auto elem: input) {
        max_tmp += elem;
        if (max_elem < max_tmp) {
            max_elem = max_tmp;
        }
        if (max_tmp < 0)
            max_tmp = 0;
    }
    return max_elem;
}
