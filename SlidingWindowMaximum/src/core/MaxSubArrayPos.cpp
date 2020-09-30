//
// Created by vincent on 9/16/20.
//
#include <set>
#include <iostream>
#include <deque>
#include "MaxSubArrayPos.h"
#include "MaxSubArrayUtils.h"

using namespace std;

template<typename T>
std::vector<T> max_sub_array_naive_sol(const std::vector<T> &input, T size_sub_array)
{
    vector<T> max_values;
    max_values.reserve(input.size() - size_sub_array + 1);
    for (T i = 0; i <= input.size() - size_sub_array; i++) {
        int max_value = input.at(i);
        for (T j = 1; j < size_sub_array; j++) {
            if (max_value < input.at(i + j)) {
                max_value = input.at(i + j);
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
template<typename T>
std::vector<T> max_sub_array_bbst_sol(const std::vector<T> &input, T size_sub_array)
{
    std::vector<T> result;
    result.reserve(input.size() - size_sub_array + 1);
    std::multiset<T> balanced_tree;
    for (T i = 0; i < input.size(); i++) {
        //std::cout << "Insert " << input[i] << std::endl;
        balanced_tree.insert(input.at(i));
        if (i >= size_sub_array - 1) {
            if (i - size_sub_array >= 0) {
                //std::cout <<  "Removing " << input[i - size_sub_array] << std::endl;
                balanced_tree.erase(balanced_tree.find(input.at(i - size_sub_array)));
            }
            int max_el = *balanced_tree.rbegin();
            //std::cout <<  "Max " << max_el << std::endl;
            result.push_back(max_el);
        }
    }
    return result;
}

template<typename T>
std::vector<T> max_sub_array_pure_rbt_sol(const std::vector<T> &input, T size_sub_array)
{
    std::vector<T> result;
    /*result.reserve(input.size() - size_sub_array + 1);
    RBTree balanced_tree;
    for (T i = 0; i < input.size(); i++) {
        balanced_tree.insertValue(input.at(i));
        if (i >= size_sub_array - 1) {
            if (i - size_sub_array >= 0) {
                balanced_tree.deleteValue(input.at(i - size_sub_array));
            }
            int max_el = balanced_tree.getMaxValue();
            result.push_back(max_el);
        }
    } */
    return result;
}

template<typename T>
std::vector<T> max_sub_array_deck_sol(const std::vector<T> &input, T size_sub_array)
{
    std::vector<T> result;
    result.reserve(input.size() - size_sub_array + 1);
    std::deque<T> priority_queue;
    for (T i = 0; i < input.size(); i++) {
        //std::cout << "Insert: " << input[i] << std::endl;
        remove_minors_element(input, priority_queue, input.at(i));
        priority_queue.push_back(i);
        remove_element_out_sub_array( priority_queue, i, size_sub_array);
        if (i - (size_sub_array - 1) >= 0) {
            T max = input.at(priority_queue.front());
            //std::cout << "****** Max " << max << " ****** " << std::endl;
            result.push_back(max);
        }
        //std::cout << "Queue size: " << priority_queue.size() << std::endl;
    }
    return result;
}

template class std::vector<int> max_sub_array_deck_sol(const std::vector<int> &input, int size_sub_array);
template class std::vector<long> max_sub_array_deck_sol(const std::vector<long> &input, long size_sub_array);
template class std::vector<int> max_sub_array_pure_rbt_sol(const std::vector<int> &input, int size_sub_array);
template class std::vector<long> max_sub_array_pure_rbt_sol(const std::vector<long> &input, long size_sub_array);
template class std::vector<int> max_sub_array_bbst_sol(const std::vector<int> &input, int size_sub_array);
template class std::vector<long> max_sub_array_bbst_sol(const std::vector<long> &input, long size_sub_array);
template class std::vector<int> max_sub_array_naive_sol(const std::vector<int> &input, int size_sub_array);
template class std::vector<long> max_sub_array_naive_sol(const std::vector<long> &input, long size_sub_array);