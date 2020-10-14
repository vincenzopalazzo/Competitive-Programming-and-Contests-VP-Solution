//
// Created by vincent on 9/14/20.
//
#include "IlyaAndQueries.h"
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename T>
vector<T> find_num_successor_elem(const std::string &input, const vector<std::pair<T, T>> &queries) {
    const char *c_string = input.data();
    std::vector<int> preprocess;
    preprocess.reserve(input.size());

    preprocess.push_back(0);
    for (std::size_t i = 0; i < input.size() - 1; i++) {
        if (c_string[i] == c_string[i + 1]) {
            preprocess.push_back(1);
            continue;
        }
        preprocess.push_back(0);
    }

    std::vector<T> result;
    result.reserve(queries.size());
    int res[input.size()];
    partial_sum(preprocess.begin(), preprocess.end(), res);
    for (size_t i = 0; i < queries.size(); i++) {
        auto query = queries.at(i);
        int val = res[query.second - 1] - res[query.first - 1];
        result.push_back(val);
    }
    return result;
}

template<typename T>
T *find_num_successor_elem_native(const std::string &input, const sol::pair<T> queries[], int size_query)
{
    const char *c_string = input.data();
    int precompute[input.size()];
    precompute[0] = 0;
    for (int i = 0; i < input.size() - 1; i++) {
        if (c_string[i] == c_string[i + 1]) {
            precompute[i + 1] = 1;
        } else {
            precompute[i + 1] = 0;
        }
    }

    int res[input.size()];
    partial_sum(precompute, precompute + input.size() + 1, res);
    int *result = new int[size_query];
    for (int i = 0; i < size_query; i++) {
        auto query = queries[i];
        printf("VAL (%d, %d)\n", res[query.second - 1], res[query.first - 1]);
        result[i] = res[query.second - 1] - res[query.first - 1];
        printf("RES %d\n", res[query.second - 1] - res[query.first - 1]);
    }
    return result;
}

template std::vector<int> find_num_successor_elem(const std::string &input, const std::vector<std::pair<int, int>> &queries);
template int *find_num_successor_elem_native(const std::string &input, const sol::pair<int> queries[], int size_query);
template class sol::pair<int>;