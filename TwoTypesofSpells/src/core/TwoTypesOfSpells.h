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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */
#include <set>
#include <vector>
#include <cassert>
#include "../test/Utils.hpp"

const cpstl::Log LOG(false);

template<typename T>
struct Spell {
    uint type;
    T damage;

    Spell(uint type, T damage) : type(type), damage(damage) {}
};

template<typename T>
struct SpellsByType {
    std::set<T> fire;
    std::set<T> lightning;
};

// Manatain the counter of no doubled spells by types
template<typename T>
struct TotSum {
    T fire = 0;
    T lightning = 0;
};

// Mantains the count of doubled spells by type
template<typename T>
struct DoubledCounter {
    T fire = 0;
    T lightning = 0;
};

template<typename T, typename R>
void update_status_by_spell(SpellsByType<T> &spells, TotSum<R> &tot_sum_by_type,
                            DoubledCounter<T> &double_counter_by_type, std::set<T> const &doubled_spells, bool is_fire) {
    std::set<T> spells_by_type;
    if (is_fire) {
        cpstl::cp_log(LOG, "Is Fire");
        spells_by_type = spells.fire;
    }else{
        cpstl::cp_log(LOG, "Is lightning");
        spells_by_type = spells.lightning;
    }
    cpstl::cp_log(LOG, "Type spell: " + std::to_string(is_fire));
    auto sum_by_type = *spells_by_type.rbegin();
    if (!is_fire)
        sum_by_type = *spells_by_type.begin();
    auto spells_doubled_size = doubled_spells.count(sum_by_type) > 0 ? 1 : 0;
    if (is_fire) {
        tot_sum_by_type.fire -= sum_by_type;
        tot_sum_by_type.lightning += sum_by_type;
        double_counter_by_type.fire -= spells_doubled_size;
        double_counter_by_type.lightning += spells_doubled_size;
        spells.fire.erase(sum_by_type);
        spells.lightning.insert(sum_by_type);
    } else {
        tot_sum_by_type.fire += sum_by_type;
        tot_sum_by_type.lightning -= sum_by_type;
        double_counter_by_type.fire += spells_doubled_size;
        double_counter_by_type.lightning -= spells_doubled_size;
        spells.lightning.erase(sum_by_type);
        spells.fire.insert(sum_by_type);
    }
}

template<typename T, typename R>
R make_final_sum(DoubledCounter<T> &doubled_counter, SpellsByType<T> &spells, TotSum<R> &tot_sum,
                 std::set<T> const &doubled_spells) {
    auto sum_double = doubled_counter.fire + doubled_counter.lightning;
    cpstl::cp_log(LOG, "Sum doubled: " + std::to_string(sum_double));
    while (spells.lightning.size() < sum_double)
        update_status_by_spell(spells, tot_sum, doubled_counter, doubled_spells, true);
    while (spells.lightning.size() > sum_double)
        update_status_by_spell(spells, tot_sum, doubled_counter, doubled_spells, false);
    while (spells.lightning.size() > 0 && spells.fire.size() > 0 &&
           *spells.fire.rbegin() > *spells.lightning.begin()) {
        update_status_by_spell(spells, tot_sum, doubled_counter, doubled_spells, true);
        update_status_by_spell(spells, tot_sum, doubled_counter, doubled_spells, false);
    }
    assert(spells.lightning.size() == sum_double);
    R final_sum = tot_sum.fire + tot_sum.lightning * 2;
    if (doubled_counter.lightning == sum_double && sum_double > 0) {
        final_sum -= *spells.lightning.begin();
        if (spells.fire.size() > 0) final_sum += *spells.fire.rbegin();
    }
    return final_sum;
}

template<typename T, typename R>
std::vector<R> calculate_max_damage(std::vector<Spell<T>> const &inputs) {
    DoubledCounter<T> double_counter;
    TotSum<R> tot_sum;
    SpellsByType<T> spells;
    std::set<T> doubled_spells;
    std::vector<R> result;
    for (auto spell : inputs) {
        auto damage = spell.damage;
        cpstl::cp_log(LOG, "Damage spell: " + std::to_string(damage));
        auto type = spell.type;
        cpstl::cp_log(LOG, "Type spell: " + std::to_string(type));
        if (spell.damage > 0) {
            // Add damage
            tot_sum.fire += spell.damage;
            spells.fire.insert(damage);
            double_counter.fire += type;
            if (type != 0) {
                doubled_spells.insert(damage);
            }
        } else {
            // remove damage
            auto damage = std::abs(static_cast<T>(spell.damage));
            auto type_selected = 0;

            if (spells.lightning.count(damage) > 0) type_selected = 1;
            else assert(spells.fire.count(damage));

            if (type_selected == 0) {
                tot_sum.fire -= damage;
                spells.fire.erase(damage);
                double_counter.fire -= type;
            } else {
                tot_sum.lightning -= damage;
                spells.lightning.erase(damage);
                double_counter.lightning -= type;
            }

            if (type == 1) {
                assert(doubled_spells.count(damage));
                doubled_spells.erase(damage);
            }
        }
        auto final_sum = make_final_sum<T, R>(double_counter, spells, tot_sum, doubled_spells);
        result.push_back(final_sum);
    }
    return result;
}
