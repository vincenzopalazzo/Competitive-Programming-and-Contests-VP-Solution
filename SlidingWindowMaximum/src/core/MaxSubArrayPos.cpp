//
// Created by vincent on 9/16/20.
//
#include <set>
#include <iostream>
#include <deque>
#include "MaxSubArrayPos.h"
#include "MaxSubArrayUtils.h"

using namespace std;

const std::vector<int> max_sub_array_naive_sol(const int inputs[], const int &size_array, const int &size_sub_array)
{
    vector<int> max_values;
    max_values.reserve(size_array - size_sub_array + 1);
    for (int i = 0; i <= size_array - size_sub_array; i++) {
        int max_value = inputs[i];
        for (int j = 1; j < size_sub_array; j++) {
            if (max_value < inputs[i + j]) {
                max_value = inputs[i + j];
            }
        }
        max_values.push_back(max_value);
    }

    return max_values;
}

/**
 * At this point I will use the multiset inside the cpp std lib but I will implement the structure in some places on GITHUB
 *
 * The method of multiset that I will use are:
 * - insert
 * - extract
 * - find
 *
 * The idea here, is that the multiset is implemented by cpp standard library with a Red and Black Three, this mean that the element
 * inside the data stuctur is sorted. In sum I can access to the maximum element inside the multiset with an sed.rbegin();
 */
const std::vector<int> max_sub_array_bbst_sol(const int input[], const int &size_array, const int &size_sub_array)
{
    std::vector<int> result;
    result.reserve(size_array - size_sub_array + 1);
    std::multiset<int> balaced_tree;
    for (int i = 0; i < size_array; i++) {
        //std::cout << "Insert " << input[i] << std::endl;
        balaced_tree.insert(input[i]);
        if (i >= size_sub_array - 1) {
            if (i - size_sub_array >= 0) {
                //std::cout <<  "Removing " << input[i - size_sub_array] << std::endl;
                balaced_tree.erase(balaced_tree.find(input[i - size_sub_array]));
            }
            int max_el = *balaced_tree.rbegin();
            //std::cout <<  "Max " << max_el << std::endl;
            result.push_back(max_el);
        }
    }
    return result;
}

const std::vector<int> max_sub_array_deck_sol(const int input[], const int &size_array, const int &size_sub_array)
{
    std::vector<int> result;
    result.reserve(size_array - size_sub_array + 1);
    std::deque<int> priority_queue;
    for (int i = 0; i < size_array; i++) {
        //std::cout << "Insert: " << input[i] << std::endl;
        remove_minors_element(input, priority_queue, input[i]);
        priority_queue.push_back(i);
        remove_element_out_sub_array( priority_queue, i, size_array, size_sub_array);
        if (i - (size_sub_array - 1) >= 0) {
            int max = input[priority_queue.front()];
            //std::cout << "****** Max " << max << " ****** " << std::endl;
            result.push_back(max);
        }
        //std::cout << "Queue size: " << priority_queue.size() << std::endl;
    }
    return result;
}
