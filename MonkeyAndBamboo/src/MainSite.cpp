//
// Created by vincent on 11/13/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T, typename R>
R estimate_dimension_k_subtraction(std::vector<T> const &inputs)
{
    R big_min = 0;
    R jump;
    for (size_t i = 1; i < inputs.size(); i++) {
        jump = inputs[i] - inputs[i - 1];
        if (jump > big_min) {
            big_min = jump;
        }
    }
    return big_min;
}

template <typename T, typename R>
bool jump(std::vector<T> const &input, R k)
{
    for(int i = 1; i < input.size(); i++)
    {
        if(input[i] - input[i-1] > k)
            return false;
        else if(input[i] - input[i-1] == k)
            k--;

    }
    return true;
}

template <typename T, typename R>
R estimate_dimension_k_bisection(std::vector<T> &inputs)
{
    R start = 0;
    R end = 10000000;
    R middle;
    while(end - start > 1)
    {
        middle = (start + end) / 2;
        if(jump(inputs, middle))
            end = middle;
        else
            start = middle;
    }
    return end;
}

int main()
{
    int T;
    scanf("%d", &T);

    for(std::size_t t = 1; t <= T; t++) {
        int size;
        scanf("%d", &size);
        vector<int> inputs;
        inputs.reserve(size + 1);
        inputs.push_back(0);
        for (std::size_t i = 0; i < size; i++) {
            int value;
            scanf("%d", &value);
            inputs.push_back(value);
        }
        int result = estimate_dimension_k_subtraction<int, int>(inputs);
        printf("Case %lu: %d\n", t, result);
    }
}
