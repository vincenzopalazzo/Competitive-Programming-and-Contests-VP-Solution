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
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <algorithm>

using namespace std;

typedef std::make_signed<std::size_t>::type ssize_t;

template<typename T>
struct Frog {
    T length_tongue;
    std::size_t position;
    std::size_t mosquito_eaten = 0;
    std::size_t input_pos;

    Frog(std::size_t position, T lengthTongue, std::size_t input_pos):
            position(position), length_tongue(lengthTongue), input_pos(input_pos) {
    }

    bool operator <(Frog const &a)const{
        return position < a.position;
    }
};

template<typename T>
struct Mosquito {
    std::size_t position;
    T dimension;

    Mosquito(std::size_t position, T dimension){
        this->dimension = dimension;
        this->position = position;
    }
};

namespace cpstl {
    template <class T>
    class SegmentTree {
    private:
        std::vector<Frog<T>> origin;
        std::vector<T> structure;

        /**
         * This function is used build the segment tree with a binary heap
         * implementation, and it use the origin array stored in the class.
         * @tparam T is the type of structure, usually it is a int or another numeric
         * type
         * @param left_index the left index of the range
         * @param right_index the right index of the range
         */
        void build_structure(int left_index, int right_index) {
            build_structure_procedure(1, left_index, right_index - 1);
        }
        /**
         * This is the sub procedure that help the build_structure procedure to make
         * the logic inside the segment tree
         * @tparam T is the type of structure, usually it is a int or another numeric
         * type
         * @param start_index
         * @param left_index
         * @param right_index
         */
        void build_structure_procedure(std::size_t start_index, std::size_t left_index,
                                       std::size_t right_index) {
            if (left_index == right_index) {
                // Leaf node will have a single element
                structure[start_index] = (origin[left_index].position + origin[left_index].length_tongue);
                return;
            }
            auto middle_point = (left_index + right_index) / 2;
            auto left_child = left_child_index(start_index);
            auto right_child = right_child_index(start_index);
            build_structure_procedure(left_child, left_index, middle_point);
            build_structure_procedure(right_child, middle_point + 1, right_index);
            // Internal node will have the sum of both of its children
            auto segment_left = structure[left_child];
            auto segment_right = structure[right_child];
            structure[start_index] = std::max(segment_left, segment_right);
        }

        T range_query_subroutine(std::size_t start_index, std::size_t left_index_now,
                                 std::size_t right_index_now, std::size_t query_left,
                                 std::size_t query_right) {
            if (query_left > right_index_now || query_right < left_index_now)
                return -1;  // outside the range
            if (left_index_now >= query_left && right_index_now <= query_right)
                return structure[start_index];  // range represented by a node is
            // completely inside the given range
            // range represented by a node is partially inside and partially outside the
            // given range
            auto middle_point = (left_index_now + right_index_now) / 2;
            auto left_child = left_child_index(start_index);
            auto right_child = right_child_index(start_index);
            auto left_segment = range_query_subroutine(
                    left_child, left_index_now, middle_point, query_left, query_right);
            auto right_segment =
                    range_query_subroutine(right_child, middle_point + 1, right_index_now,
                                           query_left, query_right);
            if (left_segment == -1) return right_segment;
            if (right_segment == -1) return left_segment;
            return std::max(left_segment, right_segment);
        }

        void update_subroutine(std::size_t start_index, std::size_t left_index, std::size_t right_index,
                               std::size_t pos, T new_value) {
            if (left_index == right_index) {
                structure[start_index] += new_value;
            } else {
                auto middle_point = (left_index + right_index) / 2;
                auto left_child = left_child_index(start_index);
                auto right_child = right_child_index(start_index);
                if (pos <= middle_point) {
                    update_subroutine(left_child, left_index, middle_point, pos, new_value);
                } else {
                    update_subroutine(right_child, middle_point + 1, right_index, pos,
                                      new_value);
                }
                auto segment_left = structure[left_child];
                auto segment_right = structure[right_child];
                structure[start_index] = std::max(segment_left, segment_right);
            }
        }

        inline std::size_t left_child_index(std::size_t const index) {
            return index * 2;
        }

        inline std::size_t right_child_index(std::size_t const index) {
            return (index * 2) + 1;
        }

    public:
        SegmentTree(std::vector<Frog<T>> &origin) : origin(origin) {
            auto size = origin.size();
            structure = std::vector<T>(size * 4);
            origin = origin;
            build_structure(0, size);
        }

        virtual ~SegmentTree() { structure.clear(); }

        T range_query(std::size_t start_index, std::size_t end_index) {
            return range_query_subroutine(1, 0, origin.size() - 1, start_index,
                                          end_index);
        }

        /**
         * This is the sub procedure that help the build_structure procedure to make
         * the logic inside the segment tree
         * @param at: it is the position in the original array, the function change
         * the value also in the original array
         * @param new_value the value that we want override in position at.
         */
        void update(std::size_t const at, T value) {
            update_subroutine(1, 0, origin.size() - 1, at, value);
        }
    };
};  // namespace cpstl

// get better name
template<typename T>
ssize_t get_position_close_frog(cpstl::SegmentTree<T> &segment_tree, std::vector<T> &index_frogs, std::size_t position_mosquito) {
    ssize_t start_range = 0;
    auto it_end_range = std::upper_bound(index_frogs.begin(), index_frogs.end(), position_mosquito);
    auto end_range = it_end_range - index_frogs.begin();
    auto pos_frog = segment_tree.range_query(start_range, end_range - 1);
    if (end_range == 0 || pos_frog < position_mosquito) {
        return -1; // no mosquito to eat
    }
    while (start_range <= end_range) {
        auto middle_point = (start_range + end_range) / 2;
        pos_frog = segment_tree.range_query(start_range, middle_point);
        if (pos_frog < position_mosquito)
            start_range = middle_point + 1;
        else
            end_range = middle_point - 1;
    }
    return start_range;
}

template<typename T, typename R>
void mosquitoes_eaten(std::vector<Frog<T>> &frogs, std::vector<Mosquito<T>> &mosquitoes) {
    std::sort(frogs.begin(), frogs.end());
    // We need to do remapping and store a vector if position
    // because the upperbound is a little bit complex with the personal structure
    // https://stackoverflow.com/questions/44245803/using-lower-bound-or-upper-bound-on-structure-in-c
    std::vector<T> index_frogs;
    index_frogs.reserve(frogs.size());
    for (auto const &frog : frogs)
        index_frogs.emplace_back(frog.position);
    auto segment_tree = cpstl::SegmentTree<T>(frogs);
    std::multiset<std::pair<std::size_t, T>> solutions;
    for (auto const &mosquito : mosquitoes) {
        auto frog_pos = solve(segment_tree, index_frogs, mosquito.position);
        if (frog_pos == -1) {
            solutions.insert(std::pair<std::size_t, T>(mosquito.position, mosquito.dimension));
        } else {
            auto frog = &frogs.at(frog_pos);
            frog->mosquito_eaten++;
            frog->length_tongue += mosquito.dimension;
            segment_tree.update(frog_pos, mosquito.dimension);
            auto new_length_tongue = frog->length_tongue + frog->position;
            while (!solutions.empty()) {
                auto new_mosquito = solutions.lower_bound(std::pair<std::size_t, T>(frog->position, 0));
                if (new_mosquito == solutions.end() || new_mosquito->first > new_length_tongue) {
                    break;
                }
                new_length_tongue += new_mosquito->second;
                frog->mosquito_eaten++;
                frog->length_tongue += new_mosquito->second;
                segment_tree.update(frog_pos, new_mosquito->second);
                solutions.erase(new_mosquito);
            }
        }
    }
    std::sort(frogs.begin(), frogs.end(), [](auto frog_a, auto frog_b){
        return frog_a.input_pos < frog_b.input_pos;
    });
}


int main() {
    int F, M;
    scanf("%d", &F);
    scanf("%d", &M);
    std::vector<Frog<long long>> frogs;
    frogs.reserve(F);
    for (int i = 0; i < F; i++) {
        std::size_t pos;
        long long len;
        scanf("%ld", &pos);
        scanf("%lld", &len);
        frogs.emplace_back(pos, len, i);
    }

    std::vector<Mosquito<long long>> mosquitoes;
    mosquitoes.reserve(M);
    for (int i = 0; i < M; i++) {
        std::size_t pos;
        long long dim;
        scanf("%ld", &pos);
        scanf("%lld", &dim);
        mosquitoes.emplace_back(pos, dim);
    }

    mosquitoes_eaten<long long, long long>(frogs, mosquitoes);
    for (auto frog : frogs)
        printf("%lu %lld\n", frog.mosquito_eaten, frog.length_tongue);

    return EXIT_SUCCESS;
}
