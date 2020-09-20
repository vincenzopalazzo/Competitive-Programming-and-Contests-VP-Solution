//
// Created by vincent on 9/20/20.
//

#include <iostream>
#include <vector>
#include <map>
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

int main() {

    int num_test_cases = 0;
    std::cin >> num_test_cases;

    std::vector<int> inputs;
    for (int i = 0; i < num_test_cases; ++i) {
        int n = 0;
        std::cin >> n;
        inputs.reserve(n);
        for (int j = 0; j < n; ++j) {
            int x = 0;
            std::cin >> x;
            inputs.push_back(x);
        }
        std::vector<std::pair<int, int>> map = calc_next_larger_elem_stack(inputs);

        int res[map.size()];
        for (auto elem : map) {
            res[elem.first] = elem.second;
        }
        for (int i = 0; i < map.size(); i++) {
            std::cout << res[i] << " ";
        }
        std::cout << "\n";
        inputs.clear();
    }

    return 0;
}