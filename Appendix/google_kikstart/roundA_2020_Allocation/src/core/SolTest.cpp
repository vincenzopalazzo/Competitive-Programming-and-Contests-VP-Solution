//
// Created by vincent on 9/14/20.
//
#include "SolTest.h"
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T, typename R>
R get_maximum_number_of_house(std::vector<T> &inputs, T buget)
{
    sort(inputs.begin(), inputs.end());
    R number_house = 0;
    for (auto elem: inputs) {
        if (buget - elem >= 0) {
            buget -= elem;
            if (buget >= 0)
                number_house++;
        }
    }
    return number_house;
}

template int get_maximum_number_of_house(std::vector<int> &inputs, int buget);