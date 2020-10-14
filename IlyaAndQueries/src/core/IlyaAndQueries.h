//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

namespace sol {
    template <typename T>
    struct pair {
        T first;
        T second;
    };
}


template<typename T>
std::vector<T> find_num_successor_elem(const std::string &input, const std::vector<std::pair<T, T>> &queries);

template<typename T>
T *find_num_successor_elem_native(const std::string &input, const sol::pair<T> queries[], int size_query);

#endif //SPYCBLOCK_SOLTEST_H
