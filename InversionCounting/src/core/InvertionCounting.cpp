//
// Created by vincent on 9/14/20.
//
#include "InvertionCounting.h"
#include <iostream>
#include "Order.h"

using namespace std;
using namespace cpstl;

template <typename T>
int count_inversion_merge_sort(std::vector<T> const &inputs)
{
    return merge_sort(inputs, 0, inputs.size() - 1);
}

template int count_inversion_merge_sort<int>(std::vector<int> const &inputs);
