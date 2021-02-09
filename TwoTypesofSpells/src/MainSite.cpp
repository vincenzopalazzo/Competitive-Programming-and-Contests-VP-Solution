#include <bits/stdc++.h>
#include <vector>
#include <cassert>

using namespace std;

template<typename T>
struct Spell {
    int type;
    T damage;

    Spell(int type, T damage) : type(type), damage(damage) {}
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
        spells_by_type = spells.fire;
    }else{
        spells_by_type = spells.lightning;
    }
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
        auto type = spell.type;
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
            damage = -damage;
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


int main(){
    std::ios_base::sync_with_stdio (false);
    int N;
    cin >> N;
    std::vector<Spell<int>> spells;
    spells.reserve(N);
    for (int i = 0; i < N; i++) {
        int type;
        int damage;
        cin >> type >> damage;
        spells.emplace_back(type, damage);
    }

    auto results = calculate_max_damage<int, long long>(spells);
    for (auto result: results)
        printf("%lld\n", result);
    return EXIT_SUCCESS;
}
