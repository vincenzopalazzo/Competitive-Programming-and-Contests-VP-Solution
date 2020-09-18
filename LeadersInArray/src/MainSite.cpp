//
// Created by vincent on 9/18/20.
//
// https://practice.geeksforgeeks.org/viewSol.php?subId=893cff7a10c039da14e8ce409ea47d3f&pid=623&user=vpalazzo1
//
#include <iostream>
#include <vector>
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

int main() {

    int num_test_cases = 0;
    std::cin >> num_test_cases;

    std::vector<int> vec;
    for (int i = 0; i < num_test_cases; ++i) {
        int n = 0;
        std::cin >> n;
        vec.reserve(n);
        for (int j = 0; j < n; ++j) {
            int x = 0;
            std::cin >> x;
            vec.push_back(x);
        }
        std::deque<int> res = get_leaders_from_array_counting_sort_custom(vec);
        for (auto elem : res)
            cout << elem << " ";
        cout << "\n";
        vec.clear();
    }

    return 0;
}
