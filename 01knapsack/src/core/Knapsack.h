//
// Created by vincent on 9/14/20.
//
#include <vector>
#include "../test/Utils.hpp"

const cpstl::Log LOG(false);

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
inline T sol_knapsack_recursion(T knapsack_capacity, std::vector<Object<T>> const &objects, size_t pos)
{
    if (knapsack_capacity == 0 || pos == 0) return 0;

    if (objects[pos - 1].weight > knapsack_capacity)
        return sol_knapsack_recursion(knapsack_capacity, objects, pos - 1);

    // Case one -> I take the obj in position n - 1
    // Case two -> I don't take the obj in position n - 1
    auto case_one = objects[pos - 1].value +
            sol_knapsack_recursion(knapsack_capacity - objects[pos - 1].weight, objects, pos - 1);
    auto case_two = sol_knapsack_recursion(knapsack_capacity, objects, pos - 1);
    return max(case_one, case_two);
}

/**
 * Feel the table with bottom up approach and avoid precomputing value that we have already
 * compute.
 * Time complexity: O(M*N);
 * Auxiliary Space complexity: O(M*N).
 */
template <typename T>
inline T sol_knapsack_bottom_up(T knapsack_capacity, std::vector<Object<T>> const &objects, std::size_t pos){
    std::vector<std::vector<T>> k(pos + 1, std::vector<T>(knapsack_capacity + 1));
    for (std::size_t i = 0; i <= pos; i++) {
        for (std::size_t w = 0; w <= knapsack_capacity; w++) {
            if (i == 0 || w == 0) {
                k[i][w] = 0;
            } else if (objects[i - 1].weight <= knapsack_capacity) {
                // val[i - 1] + K[i - 1][w - wt[i - 1]]
                auto first_val = objects[i - 1].value + k[i - 1][w - objects[i - 1].weight];
                auto second_val = k[i - 1][w];
                k[i][w] = max(first_val, second_val);
            } else {
                k[i][w] = k[i - 1][w];
            }
        }
    }
    cpstl::cp_log(LOG, "---------------- sol_knapsack_bottom_up -------------------");
    cpstl::cp_log_matrix(LOG, k);
    return k[pos][knapsack_capacity];
}

template <typename T>
inline T sol_knapsack_recursion_mem(T knapsack_capacity, std::vector<Object<T>> const &objects, int index, std::vector<std::vector<T>> &mem)
{
    if (index < 0) return 0;
    if (mem[index][knapsack_capacity] != -1)
        return mem[index][knapsack_capacity];

    if (objects[index].weight > knapsack_capacity) {
        //jump this index
        mem[index][knapsack_capacity] = sol_knapsack_recursion_mem(knapsack_capacity, objects, index - 1, mem);
        return mem[index][knapsack_capacity];
    }
    // Case one -> I take the obj in position n - 1
    // Case two -> I don't take the obj in position n - 1
    auto case_one = objects[index].value +
            sol_knapsack_recursion_mem(knapsack_capacity - objects[index].weight, objects, index - 1, mem);
    auto case_two = sol_knapsack_recursion_mem(knapsack_capacity, objects, index - 1, mem);
    mem[index][knapsack_capacity] = max(case_one, case_two);

    return mem[index][knapsack_capacity];
}

template <typename T>
inline T sol_knapsack_memorization(T knapsack_capacity, std::vector<Object<T>> const &objects, size_t pos)
{
    std::vector<std::vector<T>> mem(pos, std::vector<T>(knapsack_capacity + 1));

    for (size_t i = 0; i < pos; i++) {
        for (size_t j = 0; j <= knapsack_capacity; j++) {
            mem[i][j] = -1;
        }
    }
    auto res = sol_knapsack_recursion_mem(knapsack_capacity, objects, pos - 1, mem);
    cpstl::cp_log(LOG, "---------------- sol_knapsack_memorization -------------------");
    cpstl::cp_log_matrix(LOG, mem);
    return res;
}