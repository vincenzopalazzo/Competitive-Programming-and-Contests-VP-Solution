//
// Created by vincent on 9/14/20.
//
#include "MissingNumberInArray.h"
#include <iostream>

using namespace std;

template <typename T>
T get_missing_number_naive(std::vector<T> const &inputs)
{
    for (int i = 1; i < inputs.size(); i++) {
        T delta = inputs.at(i) - inputs.at(i - 1);
        if (delta > 1) {
            return inputs.at(i) - 1;
        }
    }
    return INT32_MAX;
}

template int get_missing_number_naive(std::vector<int> const &inputs);
