#include "SolTest.h"
#include <iostream>
#include "../Utils.cpp"

using namespace std;


template<typename T, typename R>
R calculate_max_damage(set<pair<int, T>, Comparator> const &inputs)
{
    std::cout << BOLDYELLOW;
    std::cout << "Inputs: [";
    for (auto elem: inputs) {
        cout << elem.second << ", ";
    }
    cout << "]\n";
    cout << RESET;
    if (inputs.size() == 1) return inputs.begin()->second;
    R damage = 0;
    bool doubled = false;
    for (auto spell : inputs) {
        if (doubled) {
            damage += spell.second * 2;
            doubled = false;
            continue;
        }
        if (spell.first == 1) {
            doubled = true;
        }
        damage += spell.second;
    }
    return damage;
}

template <typename T, typename R>
R calculate_max_damage_two(std::vector<std::pair<int, T>> &inputs)
{
    sort(inputs.begin(), inputs.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first > b.first && a.second > b.second;
    });
    cpstl::print_vector(inputs);
    bool doubled = false;
    R damaged = 0;
    for (auto spell : inputs) {
        if (doubled) {
            doubled = false;
            damaged += spell.second * 2;
            continue;
        }
        if (spell.first == 1) {
            doubled = true;
        }
        damaged += spell.second;
    }
    return damaged;
}

template int calculate_max_damage(set<pair<int, int>, Comparator> const &inputs);
template int calculate_max_damage_two(vector<pair<int, int>> inputs);
