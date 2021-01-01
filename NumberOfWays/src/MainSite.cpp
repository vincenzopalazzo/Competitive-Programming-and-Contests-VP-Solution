//
// Created by vincent on 11/13/20.
//
#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename R>
R count_numbers_of_ways_prefix_sum(std::vector<T> const &inputs) {
    R ways = 0;
    R sum_array = 0;
    for (auto elem : inputs)
        sum_array += elem;

    // If the sum of the items is a multiple of 3 we can keep going to search
    if (sum_array % 3 != 0) return 0;

    sum_array /= 3;
    R sum = 0;
    std::vector<int> tracking(inputs.size(), 0);
    for (int i = inputs.size() - 1; i >= 0; i--) {
        sum += inputs[i];
        if (sum == sum_array) {
            tracking[i] = 1;
        }
    }

    for (int i = inputs.size() - 2; i >= 0; i--)
        tracking[i] += tracking[i + 1];

    sum = 0;
    for (int i = 0; i + 2 < inputs.size(); i++) {
        sum += inputs[i];
        if (sum == sum_array) {
            ways += tracking[i + 2];
        }
    }

    return ways;
}

int main() {
    ios::sync_with_stdio(false);

    uint32_t N;
    cin >> N;

    vector<int64_t> inputs(N, 0);

    for (size_t i = 0; i < inputs.size(); i++) {
       cin >> inputs[i];
    }

    auto res = count_numbers_of_ways_prefix_sum<int64_t, int64_t>(inputs);
    std::cout << res << "\n";
}
