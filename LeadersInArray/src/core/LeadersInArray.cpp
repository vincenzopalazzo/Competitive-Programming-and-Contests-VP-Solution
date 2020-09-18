//
// Created by https://github.com/vincenzopalazzo on 9/14/20.
//
#include "LeadersInArray.h"
#include <deque>
using namespace std;

std::deque<int> get_leaders_from_array_counting_sort_custom(const std::vector<int> &inputs)
{
    deque<int> result;
    int max_right_value = inputs.at(inputs.size() - 1);
    max_right_value = max_right_value;
    result.push_front(max_right_value);
    for (int i = inputs.size() - 2; i >= 0; i--) {
       int actual_val = inputs.at(i);
       if (actual_val >= max_right_value) {
           max_right_value = actual_val;
           result.push_front(max_right_value);
       }
    }
    return result;
}
