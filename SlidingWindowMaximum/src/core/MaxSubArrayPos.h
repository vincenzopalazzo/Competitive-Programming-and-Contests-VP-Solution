//
// Created by vincent on 9/16/20.
//

#ifndef MAXIMUMINSUMARRAYS_MAXSUBARRAYPOS_H
#define MAXIMUMINSUMARRAYS_MAXSUBARRAYPOS_H

#include <vector>

std::vector<int> max_sub_array_naive_sol(const std::vector<int> &input, int size_sub_array);

std::vector<int> max_sub_array_bbst_sol(const std::vector<int> &input, int size_sub_array);

std::vector<int> max_sub_array_deck_sol(const std::vector<int> &input, int size_sub_array);

std::vector<int> max_sub_array_pure_rbt_sol(const std::vector<int> &input, int size_sub_array);

#endif //MAXIMUMINSUMARRAYS_MAXSUBARRAYPOS_H
