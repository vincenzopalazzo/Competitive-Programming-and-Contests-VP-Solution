//
// Created by vincent on 9/14/20.
//
#include <vector>
#include <algorithm>
#include <iostream>
#include "PashmakAndParmida.h"
#include "FenwickTree.h"

using namespace std;
using namespace cpstl;

template <typename T>
int pair_indices(std::vector<T> &inputs)
{
    vector<T> counter = vector<T>(inputs.size());
    vector<T> suffix_counter = vector<T>(inputs.size());
    auto binary_index_tree = BTreeIndex<T>(inputs.size());
    remap_array(inputs);

    for(int i = inputs.size() - 1; i >= 0; i--) {
        counter[inputs[i]]++;
        suffix_counter[i] = counter[inputs[i]]; // number occs a[i] in a[i..n-1]
        binary_index_tree.update(1, counter[inputs[i]]);
    }

    fill(counter.begin(), counter.end(), 0);

    uint64_t res = 0;
    for(int i = 0; i < inputs.size(); ++i) {
        binary_index_tree.update(-1, suffix_counter[i]);
        counter[inputs[i]]++; // number occs a[i] in a[0..i]
        res += binary_index_tree.sum(counter[inputs[i]]-1);
    }

    return res;
}

/**
 * We need to remap the array because we need an array with increase index from 1 to N.
 * Also we use the cpp to sort the new array and to resize the array in the new value.
 *
 * In this case we use the distance to calculate the size of array without duplicate.
 * @tparam T
 * @param inputs
 * @return
 */
template <typename T>
void remap_array(std::vector<T> &inputs)
{
    vector<T> remap(inputs.size());
    copy(inputs.begin(), inputs.end(), remap.begin());
    sort(remap.begin(), remap.end());
    size_t sz = distance(remap.begin(), unique(remap.begin(), remap.end()));
    remap.resize(sz);

    for(auto &x : inputs) {
        //What we can do inside this function.
        //We take the distance from the first element and the element minus of "x", inside the
        //remap element.
        //At the end we assign this value to X
        x = distance(remap.begin(), lower_bound(remap.begin(), remap.end(), x));
    }
}

template int pair_indices<int>(std::vector<int> &inputs);
template void remap_array<int>(std::vector<int> &inputs);
