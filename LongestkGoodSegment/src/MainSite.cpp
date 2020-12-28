//
// Created by vincent on 11/13/20.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1200300;

template<typename T>
std::pair<std::size_t, std::size_t> calculate_kgood_segment_two_pointer_queue(std::vector<T> const inputs, T elements)
{
    std::vector<T> frequence(N);
    std::pair<std::size_t, std::size_t> result;
    std::queue<T> queue;
    T actual_el = 0;
    std::size_t res = 0;
    for (std::size_t i = 0; i < inputs.size(); i++) {
        auto val = inputs[i];
        if (frequence[val]++ == 0)
            actual_el++;
        queue.push(val);

        while (!queue.empty() && actual_el > elements) {
            if (--frequence[queue.front()] == 0)
                actual_el--;
            queue.pop();
        }

        if (res < queue.size()) {
            res = queue.size();
            result.first = i - res + 1;
            result.second = i;
        }
    }
    result.first++;
    result.second++;
    return result;
}

template<typename T>
std::pair<std::size_t, std::size_t> calculate_kgood_segment_two_pointer(std::vector<T> const inputs, T elements)
{

    std::vector<T> count;
    count.resize(N, 0);
    std::pair<std::size_t, std::size_t> result(-1, -1);
    T current_size = 0;
    std::size_t pos = 0;
    for (std::size_t i = 0; i < inputs.size(); i++) {
        while (pos < inputs.size()) {
            auto val = inputs[pos];
            if (++count[val] == 1) current_size++;
            if (current_size > elements) {
                if (--count[val] == 0) current_size--;
                break;
            }
            pos++;
        }
        if (result.second - result.first < pos - i) {
            result.first = i;
            result.second = pos;
        }
        if (--count[inputs[i]] == 0) current_size--;
    }
    result.first++;
    return result;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    vector<uint32_t> inputs;
    inputs.reserve(n);
    for(std::size_t t = 0; t < n; t++) {
        uint32_t elem;
        scanf("%d", &elem);
        inputs.push_back(elem);
    }
    auto result = calculate_kgood_segment_two_pointer_queue<uint32_t>(inputs, k);
    printf("%lu %lu", result.first, result.second);
}
