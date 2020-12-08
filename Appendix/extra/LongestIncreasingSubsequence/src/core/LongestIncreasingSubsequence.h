//
// Created by vincent on 9/14/20.
//
#include <vector>
#include "../test/Utils.hpp"
#include "FenwickTree.h"
#include "SegmentTree.h"

const cpstl::Log LOG(true);

template<typename T, typename R>
R _lis_dynamic_programming(std::vector<T> const &input, std::size_t pos, R &max) {

    if (pos == 1) return 1;
    R res, max_ending_here = 1;

    for (std::size_t i = 1; i < pos; i++) {
        res = _lis_dynamic_programming(input, i, max);
        if (input[i - 1] < input[pos - 1] && pos + 1 > max) {
            max_ending_here = res + 1;
        }
    }

    if (max < max_ending_here) {
        max = max_ending_here;
    }
    return max_ending_here;
}

template<typename T, typename R>
R lis_dynamic_programming(std::vector<T> const &input)
{
    R max = 1;
    _lis_dynamic_programming<T, R>(input, input.size(), max);
    return max;
}

template<typename T, typename R>
R lis_dynamic_programming_with_mem(std::vector<T> const &input)
{
    std::vector<T> mem(input.size(), 1);
    for (std::size_t i = 0; i < input.size(); i++) {
        for (std::size_t j = 0; j < i; j++) {
            if (input[j] < input[i]) {
                mem[i] = std::max(mem[i], mem[j] + 1);
            }
        }
    }
    R lis = mem[0];
    for (std::size_t i = 0; i < input.size(); i++) {
        lis = std::max(lis, mem[i]);
    }
    return lis;
}

template<typename T, typename R>
R lis_dynamic_programming_binary_index_tree(std::vector<T> const &input);

template<typename T, typename R>
R lis_dynamic_programming_segment_tree(std::vector<T> const &input);

template<typename T, typename R>
R lis_dynamic_programming_bst(std::vector<T> const &input);