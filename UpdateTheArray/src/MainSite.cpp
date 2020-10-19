//
// Created by vincent on 10/17/20.
//
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct update {
    int start;
    int end;
    T value;

    update(int start, int anEnd, T value) : start(start), end(anEnd), value(value) {}
};

template<class T>
class BTreeIndex {

private:
    std::vector<T> structure; // TODO require n + 1

    int indexing(int index) {
        return index & -index;
    }

public:
    BTreeIndex(int size) {
        structure = std::vector<T>(size + 1);
    }

    /**
     * This method give the possibility to insert a new value inside the tree at the position at
     * @param value The new value that I want insert
     * @param at The position of the tree that I want insert the value.
     *
     * This function override the previous value inside the tree
     */
    void update(T const &value, int at) {
        //start to the next elem
        at++;
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
    T sum(int end) {
        T sum = 0;
        int at = end;
        while (at > 0) {
            sum += structure[at];
            at -= indexing(at);
        }
        return sum;
    }
};

template<typename T>
void update_array(std::vector<update<T>> const &updates, std::vector<int> const &queries, int size_array) {
    vector<T> result;
    result.reserve(queries.size());
    vector<T> input = vector<int>(size_array);

    for (auto update : updates) {
        auto start = update.start;
        auto end = update.end;
        while (start <= end) {
            input[start] += update.value;
            start++;
        }
    }

    for (auto query : queries) {
        printf("%d\n", input[query]);
    }
}

template<typename T>
void
update_array_binary_index_tree(std::vector<update<T>> const &updates, std::vector<int> const &queries, int size_array) {
    vector<T> result;
    result.reserve(queries.size());
    auto tree = BTreeIndex<T>(size_array);

    for (auto update : updates) {
        auto start = update.start;
        auto end = update.end;
        tree.update(update.value, start);
        tree.update(-1 * update.value, end + 1);
    }

    for (auto query : queries) {
        auto res = tree.sum(query + 1);
        printf("%d\n", res);
    }
}

int main() {
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++) {
        int size_array, size_update;
        scanf("%d %d", &size_array, &size_update);
        vector<update<int>> updates;
        updates.reserve(size_update);
        for (int j = 0; j < size_update; j++) {
            int l, r, value;
            scanf("%u%d%d", &l, &r, &value);
            updates.emplace_back(l, r, value);
        }
        int size_queries;
        cin >> size_queries;
        vector<int> queries;
        queries.reserve(size_queries);
        for (int j = 0; j < size_queries; j++) {
            int elem;
            scanf("%d", &elem);
            queries.push_back(elem);
        }

        update_array_binary_index_tree(updates, queries, size_update);
    }
}