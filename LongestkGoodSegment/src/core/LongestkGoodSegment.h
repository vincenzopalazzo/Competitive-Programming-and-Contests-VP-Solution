//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>

template<typename T>
bool check_goodness_naive(std::vector<T> const &input, std::size_t from, std::size_t to)
{
    for (int j = from + 1; j < to; j++) {
        if (input[j] != input[j - 1] + 1) return false;
    }
    return true;
}

/**
 * The problem ask to find the k_good segment and return the
 * range of the segment.
 * kgood segment is the segment that contains the k_elems consecutive numbers
 * @tparam T: input type
 */
template<typename T>
std::pair<std::size_t, std::size_t> calculate_kgood_segment_naive(std::vector<T> const &input, T k_elems)
{
    std::pair<std::size_t, std::size_t> result;
    if (k_elems == 1 || k_elems == 0) {
        result.first = result.second = k_elems;
        return result;
    }
    for (int i = 0; i < input.size() - k_elems + 1; i++) {
        if (check_goodness_naive(input, i, i + k_elems)) {
            result.first = i + 1;
            result.second = i + k_elems;
        }
    }
    return result;
}

template<typename T>
std::pair<std::size_t, std::size_t> calculate_kgood_segment_two_pointer(std::vector<T> const inputs, T elements)
{
    std::pair<std::size_t, std::size_t> result(0, 1);
    auto consecutive = 1;
    while(consecutive < elements && result.second < inputs.size()) {
        if (inputs[result.second] == inputs[result.first] + consecutive) {
            consecutive++;
            result.second++;
        } else {
            result.first++;
            consecutive = 1;
            result.second = result.first;
        }
    }
    result.first++;
    return result;
}