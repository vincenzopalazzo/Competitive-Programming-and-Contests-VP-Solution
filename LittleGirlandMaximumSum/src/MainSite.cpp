//
// Created by vincent on 1/4/21.
//
#include <vector>
#include <algorithm>
#include <cassert>
#include <ios>
#include <iostream>

using namespace std;

namespace cpstl {

    template<class T>
    class BTreeIndex {

    private:
        std::vector<T> structure;

        std::size_t indexing(std::size_t index)
        {
            return index & -index;
        }

    public:
        BTreeIndex(const std::vector<T> &structure)
        {
            this->structure.reserve(structure.size() + 1);
            this->structure[0] = 0;
            for (std::size_t i = 0; i < structure.size(); i++) {
                this->structure[i + 1] = structure[i];
            }

            std::size_t at = 1;
            while (at < this->structure.size()) {
                std::size_t at_tree = indexing(at);
                this->structure[at_tree] += this->structure[at];
                at += indexing(at);
            }
        }

        BTreeIndex(std::size_t size)
        {
            structure = std::vector<T>(size + 1, 0);
        }

        /**
         * This method give the possibility to insert a new value inside the tree at the position at
         * @param value The new value that I want insert
         * @param at The position of the tree that I want insert the value.
         *
         * This function override the previous value inside the tree
         */
        void update(T const &value, std::size_t at)
        {
            while (at < structure.size()) {
                structure[at] += value;
                at += indexing(at);
            }
        }

        /**
         * This methods calculate the sum of the path from begin to end with these value included
         * @param begin Fist element that I want calculate the prefix sum
         * @param end Last element that I want calculate the prefix sum
         * @return return the prefix sum of the array A[begin, end]
         */
        T sum(std::size_t begin, std::size_t end)
        {
            assert(begin >= 0 && end >= 0);
            T sum = 0;
            auto at = end;
            while (at > begin) {
                sum += structure[at];
                at &= at - 1;
                //at -= indexing(at);
            }
            return sum;
        }

        /**
         * This method give the possibility to calculate the value from 0 to end;
         * @param end: is the final value that you want calculate the "sum" (it is included)
         * @return the sum of the subarray A[0, end]
         */
        T sum(std::size_t end)
        {
            assert(end >= 0);
            T sum = 0;
            auto at = end;
            while (at > 0) {
                sum += structure[at];
                at &= at -1;
                //at -= indexing(at);
            }
            return sum;
        }

        /**
         * @return return the position of the minimum element
         */
        int min(T const value)
        {
            assert(false && "Not implemented yet");
        }

        /**
         * @return return the position of the maximum element;
         */
        int max(T const value)
        {
            assert(false && "Not implemented yet");
        }

    };
}

template<typename T>
static std::vector<T>
calculate_frequency_query_by_index(std::vector<std::pair<T, T>> const &queries, std::size_t size_inputs)
{
    std::vector<T> frequencies(size_inputs + 1);
    for (auto query : queries) {
        frequencies[query.first - 1]++;
        frequencies[query.second]--;
    }
    return frequencies;
}

template<typename T>
static T max_sum_of_queries(std::vector<T> &inputs, std::vector<std::pair<T, T>> &queries)
{
    auto frequencies = calculate_frequency_query_by_index(queries, inputs.size());
    // calculate prefix sum
    for (int i = 1; i < frequencies.size(); i++)
        frequencies[i] += frequencies[i - 1];
    std::sort(inputs.begin(), inputs.end());
    std::sort(frequencies.begin(), frequencies.end() - 1);
    // Resolve queries
    T max_sum = 0;
    for (int i = 0; i < inputs.size(); i++) {
        max_sum += frequencies[i] * inputs[i];
    }
    return max_sum;
}

template<typename T, typename R>
static T max_sum_of_queries_fenwick_tree(std::vector<T> &inputs, std::vector<std::pair<R, R>> &queries)
{
    auto fenwick_tree = cpstl::BTreeIndex<T>(inputs.size());

    for (auto &query : queries) {
        fenwick_tree.update(1, query.first);
        fenwick_tree.update(-1, query.second + 1);
    }
    std::sort(inputs.begin(), inputs.end());
    std::vector<T> frequencies(inputs.size() + 1, 0);
    for (int i = 1; i <= inputs.size(); i++)
        frequencies[i - 1] = fenwick_tree.sum(i);
    std::sort(frequencies.begin(), frequencies.end() - 1);
    // Resolve queries
    T max_sum = 0;
    for (int i = inputs.size() - 1; i >= 0 ; i--) {
        max_sum += frequencies[i] * inputs[i];
    }
    return max_sum;
}

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i)
        cin >> sequence[i];
    return sequence;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    long long N, Q;
    cin >> N;
    cin >> Q;
    auto inputs = get_input_sequence<long long>(N);

    std::vector<std::pair<int, int>> queries;
    queries.reserve(Q);
    long long l, r;
    for(size_t i = 0; i < Q; i++) {
        cin >> l >> r;
        queries.emplace_back(l, r);
    }

    cout << max_sum_of_queries_fenwick_tree<long long, int>(inputs, queries);
    return EXIT_SUCCESS;
}

