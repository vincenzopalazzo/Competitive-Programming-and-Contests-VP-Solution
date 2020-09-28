//
// Created by vincent on 9/16/20.
//

#ifndef MAXIMUMINSUMARRAYS_MAXSUBARRAYPOS_H
#define MAXIMUMINSUMARRAYS_MAXSUBARRAYPOS_H

#include <vector>

template<typename T>
std::vector<T> max_sub_array_naive_sol(const std::vector<T> &input, T size_sub_array);

template<typename T>
std::vector<T> max_sub_array_bbst_sol(const std::vector<T> &input, T size_sub_array);

template<typename T>
std::vector<T> max_sub_array_deck_sol(const std::vector<T> &input, T size_sub_array);

template<typename T>
std::vector<T> max_sub_array_pure_rbt_sol(const std::vector<T> &input, T size_sub_array);

#endif //MAXIMUMINSUMARRAYS_MAXSUBARRAYPOS_H
