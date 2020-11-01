#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<class T>
class BTreeIndex {

private:
    std::vector<T> structure; // TODO require n + 1

    T indexing(T index) {
        return index & -index;
    }

public:
    BTreeIndex(T size)
    {
        structure = std::vector<T>(size + 1);
    }

    void update(T const &value, T at) {
        //start to the next elem
        at++;
        while (at < structure.size()) {
            structure[at] += value;
            at += indexing(at);
        }
    }

    T sum(int end) {
        T sum = 0;
        for (++end; end > 0; end &= end - 1) sum += structure[end];
        return sum;
    }

};

template<typename T>
void remap_array(std::vector<T> &inputs) {
    vector<T> remap = vector<T>(inputs.size());
    copy(inputs.begin(), inputs.end(), remap.begin());
    sort(remap.begin(), remap.end());
    size_t sz = distance(remap.begin(), unique(remap.begin(), remap.end()));
    remap.resize(sz);

    for (auto &x : inputs) {
        x = distance(remap.begin(), lower_bound(remap.begin(), remap.end(), x));
    }
}


template<typename T>
int pair_indices(std::vector<T> &inputs) {
    vector<T> counter = vector<T>(inputs.size());
    vector<T> suffix_counter = vector<T>(inputs.size());
    auto binary_index_tree = BTreeIndex<T>(inputs.size());
    remap_array(inputs);
    for (int i = inputs.size() - 1; i >= 0; i--) {
        counter[inputs[i]]++;
        suffix_counter[i] = counter[inputs[i]]; // number occs a[i] in a[i..n-1]
        binary_index_tree.update(1, counter[inputs[i]]);
    }

    fill(counter.begin(), counter.end(), 0);

    uint64_t res = 0;
    for (int i = 0; i < inputs.size(); ++i) {
        binary_index_tree.update(-1, suffix_counter[i]);
        counter[inputs[i]]++; // number occs a[i] in a[0..i]
        res += binary_index_tree.sum(counter[inputs[i]] - 1);
    }

    return res;
}

int main() {
    uint64_t size;
    cin >> size;
    vector<uint64_t> inputs;
    inputs.reserve(size);
    for (uint64_t i = 0; i < size; i++) {
        uint64_t value;
        cin >> value;
        inputs.push_back(value);
    }

    cout << pair_indices<uint64_t>(inputs);

    return EXIT_SUCCESS;
}

template class BTreeIndex<uint64_t>;