//
// Created by vincent on 9/14/20.
//
#include "TrappingRainWater.h"

#include <vector>

using namespace std;


template <typename T>
T trapping_water_one_sol(const std::vector<T> &inputs)
{
    if (inputs.empty()) return 0;
    T water = 0;
    for (int i = 1; i < inputs.size() - 1; i++) {

        T left_max = inputs.at(i);
        for (int j = 0; j < i; j++) {
            left_max = max(left_max, inputs.at(j));
        }

        T right_max = inputs.at(i);
        for (int j = i +1; j < inputs.size(); j++) {
            right_max = max(right_max, inputs.at(j));
        }

        water += min(left_max, right_max) - inputs.at(i);
    }

    return water;
}

template <typename T>
T trapping_water_optimize_sol(const  std::vector<T> &inputs)
{
    return -1;
}

template int trapping_water_one_sol(const std::vector<int> &inputs);
template int trapping_water_optimize_sol(const std::vector<int> &inputs);
