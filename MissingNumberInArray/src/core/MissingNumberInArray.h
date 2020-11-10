//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H
#include <cstdlib>
#include <string>
#include <vector>

/**
 * This solution use a technique to avoid XOR described at the following resources.
 * https://florian.github.io/xor-trick/
 * @tparam T Input type
 * @tparam R output type
 * @param inputs inputs values
 * @return return the number that is missed inside this array
 */
template <typename T>
T get_missing_number_with_sum(std::vector<T> const &inputs, std::size_t size);

/**
 * This solution use the XOR technique.
 * https://florian.github.io/xor-trick/
 * @tparam T Input type
 * @tparam R output type
 * @param inputs inputs values
 * @return return the number that is missed inside this array
 */
template <typename T>
T get_missing_number_bitmagic(std::vector<T> const &inputs, std::size_t size);

template <typename T>
T get_missing_number_formula(std::vector<T> const &inputs, std::size_t size);


#endif //SPYCBLOCK_SOLTEST_H
