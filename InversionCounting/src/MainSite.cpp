//
// Created by vincent on 10/21/20.
//
#include <iostream>
#include <vector>

using namespace std;

namespace cpstl {

    template<typename T>
    int merge(vector<T> const &inputs, int p, int q, int r) {

        int n1 = q - p + 1;
        int n2 = r - q;
        vector<T> sub_arr_left;
        sub_arr_left.reserve(n1);
        vector<T> sub_arr_right;
        sub_arr_right.reserve(n2);

        for (int i = 0; i < n1; i++) {
            sub_arr_left.push_back(inputs.at(p + i));
        }
        for (int i = 0; i < n2; i++) {
            sub_arr_right.push_back(inputs.at(q + i + 1));
        }

        int i = 0;
        int j = 0;
        int k = 0;
        while (i < n1 && j < n2) {
            if (sub_arr_left[i] > sub_arr_right[j])
                k++;
            i++;
            j++;
        }
        return k;
    }

    template<typename T>
    int merge_sort(vector<T> const &inputs, int p, int r) {
        int tot_sum = 0;
        if (p < r) {
            int q = (p + r) / 2;
            tot_sum += merge_sort(inputs, p, q);
            tot_sum += merge_sort(inputs, q + 1, r);
            tot_sum += merge(inputs, p, q, r);
        }
        return tot_sum;
    }
}

template <typename T>
int count_inversion_merge_sort(std::vector<T> const &inputs)
{
    return cpstl::merge_sort(inputs, 0, inputs.size() - 1);
}

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i)
        cin >> sequence[i];
    return sequence;
}

int main() {
    string blank;
    size_t n_tests;
    cin >> n_tests;
    getline(cin, blank);

    for(size_t i = 0; i < n_tests; ++i) {
        size_t n;
        cin >> n;
        auto A = get_input_sequence<uint64_t>(n);
        getline(cin, blank);
        uint64_t n_invs = count_inversion_merge_sort(A);

        cout << n_invs << endl;
    }

    return 0;
}