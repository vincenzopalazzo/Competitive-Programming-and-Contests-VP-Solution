//
// Created by vincent on 9/14/20.
//
#include "IlyaAndQueries.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename T>
vector<T> find_num_successor_elem(const std::string &input, const vector<pair<T, T>> &queries)
{
    const char *c_string = input.data();
    std::vector<int> preprocess;
    preprocess.reserve(input.size());
    std::vector<T> result;
    result.reserve(queries.size());
    for (int i = 0; i < input.size() - 1; i++) {
        if (c_string[i] == c_string[i + 1]) {
            preprocess.push_back(1);
        }else {
            preprocess.push_back(0);
        }
    }

    for (int i = 0; i < queries.size(); i++) {
        auto query = queries.at(i);
        /*int sum = 0;
        for (int j = query.first - 1; j < query.second - 1; j++) {
            sum += preprocess.at(j);
        }*/
        int sub_array_size = query.second - query.first;
        int elems[sub_array_size];
        auto start = next(preprocess.begin(), query.first -1);
        auto end = next(preprocess.begin(), query.second -1);
        partial_sum(start, end, elems);
        result.push_back(*std::max_element(elems, elems + sub_array_size));
    }

    return result;
}

template std::vector<int> find_num_successor_elem(const std::string &input, const std::vector<std::pair<int, int>> &queries);