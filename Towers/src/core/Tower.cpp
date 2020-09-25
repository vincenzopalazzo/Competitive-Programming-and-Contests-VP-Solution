//
// Created by vincent on 9/14/20.
//
#include "Tower.h"
#include <iostream>
#include <algorithm>
#include "Search.h"

using namespace std;

template<typename T> // Computation time is O(n log n)
pair<T, int> calculate_number_of_tower(vector<T> &inputs) {
    pair<T, int> result;
    int max_height = 1;
    int actual_max = 1;
    int number_tower = 0;

    sort(inputs.begin(), inputs.end()); // O(n log n)
    for (int i = 0; i < inputs.size(); i++) { // O(N)
        int pos = cpstl::binary_search(inputs, inputs.at(i), i + 1, inputs.size() - 1); // O(log n - i)
        if (pos != -1) {
            actual_max++;
        } else {
            if (actual_max > max_height) max_height = actual_max;
            actual_max = 1;
            number_tower++;
        }
    }

    result.first = max_height;
    result.second = number_tower;
    return result;
}

template class pair<int, int> calculate_number_of_tower<int>(vector<int> &inputs);
