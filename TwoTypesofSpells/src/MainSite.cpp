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
R calculate_max_damage(std::vector<std::pair<int, T>> const &inputs)
{
    std::set<T> lightningSpells;
    std::set<T> fireSpells;
    for (auto elem: inputs) {
        if(elem.first == 1)
            lightningSpells.insert(elem.second);
        else
            fireSpells.insert(elem.second);
    }
    R totDamage = 0;
    bool doubled = false;
    //while (!lightningSpells.empty()) {
    for (auto elem : lightningSpells) {
        if (elem > 0) {
            if (doubled) {
                totDamage += 2 * elem;
            } else {
                doubled = true;
                totDamage += elem;
            }
        }
    }
    //while (!fireSpells.empty()) {
    for (auto elem = fireSpells.crbegin() ; elem != fireSpells.crend(); elem++) {
        if (*elem > 0) {
            if (doubled) {
                totDamage += 2 * *elem;
                doubled = false;
            } else {
                totDamage += *elem;
            }
        }
    }
    return totDamage;
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
            auto p = std::find(spells.begin(), spells.end(), pair<int, long long>(spell.first, std::abs(spell.second)));
            spells.erase(p);
        }
        cout << calculate_max_damage<long long, long long>(spells) << "\n";
    }
}
