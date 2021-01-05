/**
 * Binary index tree data structure implementation
 * https://github.com/vincenzopalazzo/cpstl
 *
 * Copyright (C) 2020  Vincenzo Palazzo vincenzopalazzodev@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#include <vector>

namespace cpstl {

    template<class T>
    class BTreeIndex {
    private:
        std::vector<T> structure;

        inline int indexing(int index)
        {
            return index& -index;
        }
    public:
        BTreeIndex(std::vector<T> const &structure)
        {
            this->structure.reserve(structure.size() + 1);
            this->structure[0] = 0;
            for (std::size_t i = 0; i < structure.size(); i++) {
                this->structure[i + 1] = structure[i];
            }

            int at = 1;
            while (at < this->structure.size()) {
                int at_tree = indexing(at);
                this->structure[at_tree] += this->structure[at];
                at += indexing(at);
            }
        }

        BTreeIndex(std::size_t size)
        {
            structure = std::vector<T>(size + 1);
        }

        /**
         * This method give the possibility to insert a new value inside the tree at the position at
         * @param value The new value that I want insert
         * @param at The position of the tree that I want insert the value.
         *
         * This function override the previous value inside the tree
         */
        inline void update(int at, T const value)
        {
            while (at < structure.size()) {
                structure[at] += value;
                at += indexing(at);
            }
        }

        /**
         * This method give the possibility to calculate the value from 0 to end;
         * @param end: is the final value that you want calculate the "sum" (it is included)
         * @return the sum of the subarray A[0, end]
         */
        inline T sum(int end)
        {
            T sum = 0;
            auto at = end;
            while (at > 0) {
                sum += structure[at];
                at &= at -1;
                //at -= indexing(at);
            }
            return sum;
        }
    };
}