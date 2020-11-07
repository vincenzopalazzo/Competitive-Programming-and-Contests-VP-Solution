//
// Created by vincent on 9/14/20.
//
#include "InversionCounting.h"
#include "Order.h"

using namespace std;
using namespace cpstl;

template <typename T>
T count_inversion_merge_sort(std::vector<T> &inputs)
{
    return merge_sort(inputs, 0, inputs.size() - 1);
}

template int count_inversion_merge_sort<int>(std::vector<int> &inputs);
