//
// Created by vincent on 9/14/20.
//
#include "LittleGirlAndMaximumSum.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

template<typename T>
T max_sum_of_queries(std::vector<T> &inputs, const std::vector<std::pair<T, T>> &queries)
{
    //Sort the list inside
    //sort(inputs.begin(), inputs.end());

    T sum = 0;
    for (int i = 0; i < queries.size(); i++) {
        pair<T, T> query = queries.at(i);
        printf("Query (%d, %d)\n", query.first, query.second);
        auto start = std::next(inputs.begin(), query.first - 1);
        auto end = std::next(inputs.begin(), query.second - 1);
        printf("Element start %d, end %d\n", *start, *end);
        partial_sum(inputs.begin(), inputs.end(), inputs.begin());
        sum += *inputs.begin();
    }
    return sum;

}

template int max_sum_of_queries(std::vector<int> &inputs, const std::vector<std::pair<int, int>> &queries);