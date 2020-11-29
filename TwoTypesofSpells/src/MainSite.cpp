//
// Created by vincent on 11/13/20.
//
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T, typename R>
R calculate_max_damage_two(vector<pair<int, T>> inputs)
{
    sort(inputs.begin(), inputs.end(), [](pair<int, T> a, pair<int, T> b){
        return a.first > b.first && a.second > b.second;
    });
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

int main()
{
    int speels;
    scanf("%d", &speels);
    vector<pair<int, long long>> spells;
    spells.reserve(speels);
    for(std::size_t t = 1; t <= speels; t++) {
        int type;
        int power;
        scanf("%d", &type);
        scanf("%d", &power);
        pair<int, long long> spell(type, power);
        if (spell.second > 0) {
            spells.push_back(spell);
        } else {
            auto p = std::find(spells.begin(), spells.end(), pair<int, long long>(spell.first, fabs(spell.second)));
            spells.erase(p);
        }
        cout << calculate_max_damage_two<long long, long long>(spells) << "\n";
    }
}
