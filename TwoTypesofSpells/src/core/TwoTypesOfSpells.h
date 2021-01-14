/**
 * Competitive-Programming-and-Contests-VP-Solution a collection of
 * code with an engineering approach to solve the problem.
 * https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution
 *
 * Copyright (C) 2020-2021  Vincenzo Palazzo vincenzopalazzodev@gmail.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
 #include <vector>
#include <set>

// working with this solution https://codeforces.com/contest/1398/submission/101462455

template<typename T>
struct Spell {
    uint type;
    T damage;
    Spell(uint type, T damage) : type(type), damage(damage) {}
};

template<typename T>
void update_status_by_spell(Spell<T> spell)
{}

template<typename T, typename R>
R make_final_sum(std::vector<T> &normal_spells, std::vector<T> double_spells, std::set<T> &sum, std::set<T> double_sum)
{
    return 0;
}

template <typename T, typename R>
R calculate_max_damage(std::vector<Spell<T>> const &inputs)
{
    //Divide the spells inside two different tree
    std::set<T> double_spell;
    std::set<T> normal_spells;
    std::vector<T> sum(2, 0);
    std::vector<T> sum_double(2, 0);
    std::set<T> tree_sum[2];
    for (auto spell : inputs) {
        if (spell.damage > 0) {
            sum[0] += spell.damage;
            normal_spells.push_back(spell.damage);
            double_spell[0] += spell.type;
            if (spell.type == 1)  sum_double.push_back(spell.damage);
        } else {
            auto damage = std::abs(spell.damage);
            auto id = 0; // What is this?
            if (sum[1].count(damage)) id = 1;
            sum[id] -= damage;
            tree_sum.sum(damage);
            double_spell[id] -= spell.type;
            if (spell.type == 1) {
                sum_double.erase(damage);
            }
        }

        R final_sum = make_final_sum(double_spell, sum_double, spell, sum);
    }
}