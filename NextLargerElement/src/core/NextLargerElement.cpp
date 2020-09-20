//
// Created by vincent on 9/14/20.
//
#include "NextLargerElement.h"
#include <iostream>
#include <stack>

using namespace std;

std::vector<pair<int, int>> calc_next_larger_elem_stack(const std::vector<int> &inputs)
{
    std::stack<pair<int, int>> stack;
    std::vector<pair<int, int>> result;
    stack.emplace(0, inputs.at(0));
    for (int i = 1; i < inputs.size(); i++) {
        if (stack.empty()) {
            stack.emplace(i, inputs.at(i));
            continue;
        }
        int next = inputs.at(i);
        while (!stack.empty() && stack.top().second < next) {
            if (stack.top().second < next) {
                result.emplace_back(stack.top().first, next);
                stack.pop();
            }
        }
        stack.emplace(i, next);
    }

    while (!stack.empty()) {
        result.emplace_back(stack.top().first, -1);
        stack.pop();
    }
    return result;
}

std::vector<int> calc_next_larger_elem_naive(const std::vector<int> &inputs)
{
    std::vector<int> result;
    result.reserve(inputs.size());

    for (int i = 0; i < inputs.size(); i++) {
        for (int j =  i + 1; j <= inputs.size(); j++) {
            if (j == inputs.size()) {
                result.push_back(-1);
                break;
            } else if (inputs.at(i) < inputs.at(j)) {
                result.push_back(inputs.at(j));
                break;
            }
        }
    }
    return result;
}

// The recursion at the moment look like a bad idea because with the big number the stack can be very large
int get_larger_elem(const std::vector<int> &inputs, int input_pos, int gap);

std::vector<int> calc_next_larger_elem_naive_recursive(const std::vector<int> &inputs)
{
    std::vector<int> result;
    result.reserve(inputs.size());
    for (int i = 0; i < inputs.size(); i++) {
        int res = get_larger_elem(inputs, i, 1);
        result.push_back(res);
    }
    return result;
}

int get_larger_elem(const std::vector<int> &inputs, int input_pos, int gap)
{
    if (input_pos >= inputs.size() - 1 || input_pos + gap >= inputs.size()) {
        return -1;
    } else if (inputs.at(input_pos) < inputs.at(input_pos + gap)) {
        return inputs.at(input_pos + gap);
    }
    return get_larger_elem(inputs, input_pos, gap + 1);
}
