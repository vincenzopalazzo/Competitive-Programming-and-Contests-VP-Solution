//
// Created by vincent on 9/14/20.
//
#include "MissingNumberInArray.h"
#include <iostream>

using namespace std;

template <typename T>
T get_missing_number_with_sum(std::vector<T> const &inputs, std::size_t size)
{
    T sum = 0;

    for (std::size_t i = 1; i <= size; i++) {
        sum += i;
    }

    for (size_t i = 0; i < inputs.size(); i++) {
        sum -= inputs.at(i);
    }

    return sum;
}

template <typename T>
T get_missing_number_bitmagic(std::vector<T> const &inputs, std::size_t size)
{
    T xor_val = 0;

    for (int i = 1; i <= size; i++) {
        xor_val ^= i;
    }
    for (int i = 0; i < inputs.size(); i++) {
        xor_val ^= inputs.at(i);
    }
    return xor_val;
}

template <typename T>
T get_missing_number_formula(std::vector<T> const &inputs, std::size_t size)
{
    T sum = 0;
    T tot_sum = size * (size + 1) / 2;
    for (int i = 0; i < inputs.size(); i++) {
        sum += inputs.at(i);
    }
    return tot_sum - sum;
}

template int get_missing_number_with_sum(std::vector<int> const &inputs, std::size_t size);
template int get_missing_number_bitmagic(std::vector<int> const &inputs, std::size_t size);
template int get_missing_number_formula(std::vector<int> const &inputs, std::size_t size);