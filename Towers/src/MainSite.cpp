//
// Created by vincent on 9/25/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
int binary_search(std::vector<T> const &inputs, T key, int start, int end)
{
    if(start > end) return -1;
    // We go to te middle of algorithm
    int middle_pos = start + (end - start) / 2;
    if (middle_pos > end) return - 1;
    if (inputs.at(middle_pos) > key) {
        //sub array [start, middle_pos]
        return binary_search(inputs, key, start, middle_pos - 1);
    } else if (inputs.at(middle_pos) < key) {
        // sub array [middle_pos - end]
        return binary_search(inputs, key, middle_pos + 1, end);
    }
    return middle_pos;
}

template<typename T>
pair<T, int> calculate_number_of_tower(vector<T> &inputs) {
    pair<T, int> result;
    int max_height = 1;
    int actual_max = 1;
    int number_tower = 0;

    sort(inputs.begin(), inputs.end()));
    for (int i = 0; i < inputs.size(); i++) {
        int pos = binary_search(inputs, inputs.at(i), i + 1, inputs.size() - 1);
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

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(int i = 0; i < n; ++i)
        cin >> sequence[i];
    return sequence;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    auto inputs = get_input_sequence<int>(n);

    std::pair<int, int> result = calculate_number_of_tower(inputs);
    std::cout << result.first << " " << result.second << std::endl;

    return 0;
}
