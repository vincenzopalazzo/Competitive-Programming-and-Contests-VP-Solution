//
// Created by vincent on 9/14/20.
//
#include "IlyaAndQueries.h"
#include <iostream>
#include <algorithm>
#include <bitset>

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
        int sum = 0;
        for (int j = query.first - 1; j < query.second - 1; j++) {
            sum += preprocess.at(j);
        }
        result.push_back(sum);
    }

    return result;
}

template std::vector<int> find_num_successor_elem(const std::string &input, const std::vector<std::pair<int, int>> &queries);