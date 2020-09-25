//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H
#include <cstdlib>
#include <string>
#include <vector>
#include <map>

std::vector<int64_t> calc_next_larger_elem_naive_recursive(const std::vector<int64_t> &inputs);

std::vector<std::pair<int, int64_t>> calc_next_larger_elem_stack(const std::vector<int64_t> &inputs);

std::vector<int64_t> calc_next_larger_elem_naive(const std::vector<int64_t> &inputs);

#endif //SPYCBLOCK_SOLTEST_H
