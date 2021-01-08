/**
 * Competitive Programming Standard library a collection of code and algorithm
 * to solve Competitive programming problem and problem give at coding interview.
 * https://github.com/vincenzopalazzo/cpstl
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
#include <bits/stdc++.h>
#include "colors.h"

namespace cpstl {

    struct Log {
        bool enable = false;

        Log(bool enable) : enable(enable) {}
    };

    template<typename T>
    inline void print_vector(std::vector<T> const &inputs)
    {
        std::cout << BOLDYELLOW;
        std::cout << "Inputs: [";
        for (int i = 0; i < inputs.size(); i++) {
            if (i == inputs.size() - 1) {
                std::cout << inputs[i] << "]";
                continue;
            }
            std::cout << inputs[i] << ", ";
        }
        std::cout << "\n";
        std::cout << RESET;
    }

    /**
     * This procedure is wrote to load data from the test data
     * download from the https://www.hackerrank.com/
     * @tparam T update of vector
     * @return return a single vector.
     */
    template<typename T>
    inline std::vector<T> load_input_from_string(std::string &input_string)
    {
        std::string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
            return x == y and x == ' ';
        });

        input_string.erase(new_end, input_string.end());

        while (input_string[input_string.length() - 1] == ' ') {
            input_string.pop_back();
        }

        std::vector<std::string> splits;
        char delimiter = ' ';

        size_t i = 0;
        size_t pos = input_string.find(delimiter);

        while (pos != std::string::npos) {
            splits.push_back(input_string.substr(i, pos - i));

            i = pos + 1;
            pos = input_string.find(delimiter, i);
        }

        splits.push_back(input_string.substr(i, std::min(pos, input_string.length()) - i + 1));

        return splits;
    }

    inline void cp_log(Log log, std::string message)
    {
        if (!log.enable) return;
        std::cout << BOLDYELLOW;
        std::cout << message;
        std::cout << "\n";
        std::cout << RESET;
    }

    template<typename T>
    inline void cp_log(Log log, std::vector<T> const &inputs)
    {
        if (!log.enable) return;
        std::cout << BOLDYELLOW;
        print_vector(inputs);
        std::cout << "\n";
        std::cout << RESET;
    }

    // function to load a segment from file from file
    template<typename T>
    inline std::vector<T> load_sequences_from_file(std::string const &name_file)
    {
        std::ifstream file_to_load(name_file);
        assert(file_to_load.is_open() && "File to load unable");
        int size_array;
        int size_queries;
        file_to_load >> size_array;
        file_to_load >> size_queries;
        std::vector<T> inputs;
        inputs.reserve(size_array);
        for (int i = 0; i < size_array; i++) {
            int value;
            file_to_load >> value;
            inputs.push_back(value);
        }
        return inputs;
    }

    template<typename T>
    inline std::vector<T> load_query_from_file(std::string const &name_file)
    {
        std::ifstream file_to_load(name_file);
        assert(file_to_load.is_open() && "File to load unable");
        int size_array;
        int size_queries;
        file_to_load >> size_array;
        file_to_load >> size_queries;
        for (int i = 0; i < size_array; i++) {
            int value;
            file_to_load >> value;
        }
        std::vector<T> inputs;
        inputs.reserve(size_queries);
        for (int i = 0; i < size_queries; i++) {
            std::size_t x_val, y_val;
            int value;
            file_to_load >> x_val;
            file_to_load >> y_val;
            file_to_load >> value;
            inputs.emplace_back(x_val, y_val, value);
        }
        return inputs;
    }

    template<typename T>
    inline std::vector<T> load_result_from_file(std::string const &name_file)
    {
        std::ifstream file_to_load(name_file);
        assert(file_to_load.is_open() && "File to load unable");
        std::vector<T> inputs;
        T value;
        while (file_to_load >> value) {
            inputs.push_back(value);

        }
        return inputs;
    }
}