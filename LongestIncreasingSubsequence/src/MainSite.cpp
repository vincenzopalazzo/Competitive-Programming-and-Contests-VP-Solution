//
// Created by vincent on 11/13/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T, typename R>
R lis_dynamic_programming_with_mem(std::vector<T> const &input)
{
    std::vector<T> mem(input.size(), 1);
    for (std::size_t i = 0; i < input.size(); i++) {
        for (std::size_t j = 0; j < i; j++) {
            if (input[j] < input[i]) {
                mem[i] = std::max(mem[i], mem[j] + 1);
            }
        }
    }
    R lis = mem[0];
    for (std::size_t i = 0; i < input.size(); i++) {
        lis = std::max(lis, mem[i]);
    }
    return lis;
}

int main()
{
    int T;
    scanf("%d", &T);

    for(std::size_t t = 1; t <= T; t++) {
        int size;
        scanf("%d", &size);
        int buget;
        scanf("%d", &buget);
        vector<int> inputs;
        inputs.reserve(size);
        for (std::size_t i = 0; i < size; i++) {
            int value;
            scanf("%d", &value);
            inputs.push_back(value);
        }
        int result = get_maximum_number_of_house<int, int>(inputs, buget);
        printf("Case #%lu: %d\n", t, result);
    }
}
