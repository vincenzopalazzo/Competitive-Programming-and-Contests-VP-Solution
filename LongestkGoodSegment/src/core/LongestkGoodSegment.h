//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>
#include <queue>

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
    std::vector<T> count(N);
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