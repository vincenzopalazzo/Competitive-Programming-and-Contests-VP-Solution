/**
 * Competitive-Programming-and-Contests-VP-Solution a collection of
 * code with an engineering approach to solve the problem.
 * https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution
 *
 * Copyright (C) 2020-2021  Vincenzo Palazzo vincenzopalazzodev@gmail.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include "MonkeyAndBamboo.h"
#include <iostream>
#include <algorithm>
#include "../Utils.cpp"

using namespace std;

template <typename T, typename R>
R estimate_dimension_k_trivial(std::vector<T> const &inputs)
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

template <typename T, typename R>
R estimate_dimension_k_subtraction(std::vector<T> const &inputs)
{
    R big_min = inputs[0];
    R jump;
    for (size_t i = 1; i < inputs.size(); i++) {
        jump = inputs[i] - inputs[i - 1];
        if (jump >= big_min) {
            big_min = jump;
        }
    }
    return big_min;
}

template <typename T, typename R>
bool jump(std::vector<T> const &input, R k)
{
    for(int i = 1; i < input.size(); i++)
    {
        if(input[i] - input[i-1] > k)
            return false;
        else if(input[i] - input[i-1] == k)
            k--;

    }
    return true;
}

template <typename T, typename R>
R estimate_dimension_k_bisection(std::vector<T> &inputs)
{
    R start = 0;
    R end = 10000000;
    R middle;
    while(end - start > 1)
    {
        middle = (start + end) / 2;
        if(jump(inputs, middle))
            end = middle;
        else
            start = middle;
    }
    return end;
}


template int estimate_dimension_k_trivial<int, int>(std::vector<int> const &inputs);
template int estimate_dimension_k_subtraction<int, int>(std::vector<int> const &inputs);
template int estimate_dimension_k_bisection<int, int>(std::vector<int> &inputs);
template bool jump<int, int>(std::vector<int> const &input, int k);
