//
// Created by vincent on 11/13/20.
//
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
bool check_goodness(std::vector<T> const &input, std::size_t from, std::size_t to)
{
    for (int j = from + 1; j < to; j++) {
        if (input[j] != input[j - 1] + 1) return false;
    }
    return true;
}

template<typename T>
std::pair<std::size_t, std::size_t> calculate_kgood_segment(std::vector<T> const &input, T k_elems)
{
    std::pair<std::size_t, std::size_t> result;
    if (k_elems == 1 || k_elems == 0) {
        result.first = result.second = k_elems;
        return result;
    }
    for (int i = 0; i < input.size() - k_elems + 1; i++) {
        if (check_goodness(input, i, i + k_elems)) {
            result.first = i + 1;
            result.second = i + k_elems;
        }
    }
    return result;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    vector<int> inputs;
    inputs.reserve(n);
    for(std::size_t t = 0; t < n; t++) {
        int elem;
        scanf("%d", &elem);
        inputs.push_back(elem);
    }
    auto result = calculate_kgood_segment(inputs, k);
    printf("%lu %lu", result.first, result.second);
}
