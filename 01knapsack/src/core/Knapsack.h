//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H
#include <vector>

template <typename T>
struct Object {
    T weight;
    T value;

    Object(T weight, T value) : weight(weight), value(value) {}
};

template <typename T>
inline T max(T x, T y) {
    return (x < y) ? y : x;
}

template <typename T>
inline T sol_knapsack_trivial(T knapsack_capacity, std::vector<Object<T>> objects, size_t pos)
{
    if (knapsack_capacity == 0 || pos == 0) return 0;

    if (objects[pos - 1].weight > knapsack_capacity)
        return sol_knapsack_trivial(knapsack_capacity, objects, pos - 1);

    // Case one -> I take the obj in position n - 1
    // Case two -> I don't take the obj in position n - 1
    auto case_one = objects[pos - 1].value + sol_knapsack_trivial(knapsack_capacity - objects[pos - 1].weight, objects, pos - 1);
    auto case_two = sol_knapsack_trivial(knapsack_capacity, objects, pos - 1);
    return max(case_one, case_two);
}

#endif //SPYCBLOCK_SOLTEST_H
