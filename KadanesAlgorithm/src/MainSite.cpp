//
// Created by vincent on 9/18/20.
// https://practice.geeksforgeeks.org/viewSol.php?subId=bcdd649ba5a2e68f0174baef18af551f&pid=106&user=vpalazzo1
//

#include <iostream>
#include <vector>

using namespace std;

int sum_contiguous_sub_arr(const std::vector<int> &input)
{
    int max_elem = INT32_MIN;
    int max_tmp = 0;
    for (auto elem: input) {
        max_tmp += elem;
        if (max_elem < max_tmp) {
            max_elem = max_tmp;
        }
        if (max_tmp < 0)
            max_tmp = 0;
    }
    return max_elem;
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
        cout << sum_contiguous_sub_arr(vec) << " ";
        cout << "\n";
        vec.clear();
    }

    return 0;
}