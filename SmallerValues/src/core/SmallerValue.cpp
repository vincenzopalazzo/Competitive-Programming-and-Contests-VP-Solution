//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include "SmallerValue.h"
#include "../colors.h"
#include "../Utils.cpp"

using namespace std;
using namespace cpstl;


template <typename T, typename R>
std::vector<R> get_numbers_of_smaller_number_trivial(std::vector<T> &inputs, std::vector<Query<T>> queries)
{
    vector<T> response;
    response.reserve(queries.size());
    for (auto query : queries) {
        R result = 0;
        for (int i = query.start; i <= query.end; i++) {
            if (inputs.at(i) <= query.value){
                result++;
            }
        }
        response.push_back(result);
    }
    return response;
}

template <typename T, typename R>
std::vector<R> get_numbers_of_smaller_number_fenwick_tree(std::vector<T> &inputs, std::vector<Query<T>> queries)
{
    return {};
}


template vector<int> get_numbers_of_smaller_number_trivial(std::vector<int> &inputs, std::vector<Query<int>> queries);
template vector<int> get_numbers_of_smaller_number_fenwick_tree(std::vector<int> &inputs, std::vector<Query<int>> queries);
template class Query<int>;


