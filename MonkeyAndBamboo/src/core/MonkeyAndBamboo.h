//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H
#include <cstdlib>
#include <string>
#include <vector>

template <typename T, typename R>
R estimate_dimension_k_trivial(std::vector<T> const &inputs);

template <typename T, typename R>
R estimate_dimension_k_subtraction(std::vector<T> const &inputs);


template <typename T, typename R>
R estimate_dimension_k_bisection(std::vector<T> &inputs);

#endif //SPYCBLOCK_SOLTEST_H
