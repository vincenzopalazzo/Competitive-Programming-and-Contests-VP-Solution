//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H

#include <vector>
#include "../test/Utils.hpp"

template <typename T>
T fibonacci_num(T num)
{
    if (num == 0) return 0;
    if (num == 1) return 1;
    return fibonacci_num(num - 1) + fibonacci_num(num - 2);
}

template <typename T>
T _fibonacci_num_mem(T num, std::vector<T> &mem)
{
    if (mem[num] != -1) return mem[num];
    auto calc = 0;
    if (num == 0)
        calc = 0;
    else if (num == 1)
        calc = 1;
    else
        calc = _fibonacci_num_mem(num - 1, mem) + _fibonacci_num_mem(num - 2, mem);
    mem[num] = calc;
    return mem[num];
}

template <typename T>
T fibonacci_num_mem(T num)
{
    std::vector<T> mem(num + 1, -1);
    return _fibonacci_num_mem(num, mem);
}

template <typename T>
T fibonacci_num_tab(T num)
{
    std::vector<T> tab({0, 1});
    for (int i = 2; i <= num; i++) {
        tab.push_back(tab[i - 1] + tab[i - 2]);
    }
    return tab[num];
}



#endif //SPYCBLOCK_SOLTEST_H
