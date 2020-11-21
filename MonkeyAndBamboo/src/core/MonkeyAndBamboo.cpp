//
// Created by vincent on 9/14/20.
//
#include "MonkeyAndBamboo.h"
#include <iostream>
#include <algorithm>
#include "../Utils.cpp"

using namespace std;

template <typename T, typename R>
R estimate_dimension_k(std::vector<T> const &inputs)
{
    R k;
    vector<T> differences;
    differences.resize(inputs.size());

    T prev = 0;
    for (std::size_t i = 0; i < inputs.size(); i++) {
        T diff = inputs.at(i) - prev;
        differences[i] = diff;
        prev = inputs.at(i);
    }

    sort(differences.begin(), differences.end());
    //cpstl::print_vector(differences);
    k = differences.at(inputs.size() - 1);
    return k;
}

template int estimate_dimension_k<int, int>(std::vector<int> const &inputs);
