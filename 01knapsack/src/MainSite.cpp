//
// Created by vincent on 11/13/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
struct Object {
    T weight;
    T value;

    Object(T weight, T value) : weight(weight), value(value) {}
};

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
    return res;
}

int main()
{
    int T, size;
    cin >> T;
    cin >> size;
    vector<Object<int>> inputs;
    for(int t = 0; t < size; t++) {
        int w, val;
        cin >> w;
        cin >> val;
        inputs.emplace_back(w, val);
    }
    auto res = sol_knapsack_memorization(T, inputs, inputs.size());
    std::cout << res << "\n";
}
