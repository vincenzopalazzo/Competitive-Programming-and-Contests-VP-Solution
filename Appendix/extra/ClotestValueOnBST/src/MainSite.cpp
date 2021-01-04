//
// Created by vincent on 11/13/20.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T, typename R>
R get_maximum_number_of_house(std::vector<T> &inputs, T buget)
{
    sort(inputs.begin(), inputs.end());
    R number_house = 0;
    for (auto elem: inputs) {
        if (buget - elem >= 0) {
            buget -= elem;
            if (buget >= 0)
                number_house++;
        }
    }
    return number_house;
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
