//
// Created by vincent on 9/14/20.
//
#include <vector>
#include <set>

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