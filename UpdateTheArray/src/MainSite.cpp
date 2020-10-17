//
// Created by vincent on 10/17/20.
//
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct update {
    int start;
    int end;
    T value;

    update(int start, int anEnd, T value) : start(start), end(anEnd), value(value) {}
};

template <typename T>
void update_array(std::vector<update<T>> const &updates, std::vector<int> const &queries, int size_array)
{
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

int main()
{
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

        update_array(updates, queries, size_update);
    }
}