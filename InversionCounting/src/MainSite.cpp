//
// Created by vincent on 10/21/20.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//Debug code https://www.hackerrank.com/challenges/ctci-merge-sort/problem

namespace cpstl {

    /**
     * The procedure is called inside the main function merge_sort,
     * this permitted to subdivide the function inside the procedure and
     * is easy change the function with somethings else to resolve some competitive programming problem.
     *
     * P.S: The source of this code is the teorical book on algorithms
     * @tparam T is a generic type, can be all type numeric that we want, by default is supported only the int (for the moment)
     * but your can extend it.
     * @param inputs Is a array or sequence of number that we want sort.
     * @param p an array index <= of q
     * @param q an array index < of r but >= or p
     * @param r an array index < of p and q.
     W*/
    template<typename T, typename R>
    R merge(vector<T> &inputs, size_t p, size_t q, size_t r)
    {
        size_t n1 = q - p + 1;
        size_t n2 = r - q;
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

        size_t i = 0;
        size_t j = 0;
        R inversion = 0;
        int k = p;
        //cout << YELLOW;
        while (i < n1 && j < n2) {
            if (sub_arr_left[i] <= sub_arr_right[j]) {
                inputs[k] = sub_arr_left[i];
                i++;
            } else {
                /* cout << "From: " << sub_arr_left[i] << "\n";
                 cout << "Invesion with: " << sub_arr_right[j] << "\n";
                 cout << BOLDRED << "-------- DEBUG ------------------\n";
                 cout << BOLDRED << "sub_arr_left.size() - i = " << sub_arr_left.size() - i << "\n";
                 cout << BOLDRED << "q - i = " << q - i << "\n";*/
                inputs[k] = sub_arr_right[j];
                inversion += sub_arr_left.size() - i;
                //cout << "Inversion number found " << inversion << YELLOW << "\n";
                j++;
            }
            k++;
        }

        // copy the remain elements inside the input
        while (i < n1) {
            inputs[k] = sub_arr_left[i];
            i++;
            k++;
        }
        // copy the remain elements inside the input
        while (j < n2) {
            inputs[k] = sub_arr_right[j];
            j++;
            k++;
        }
        //cout << RESET;
        return inversion;
    }

    template<typename T, typename R>
    R merge_sort(vector<T> &inputs, size_t p, size_t r) {
        R tot_sum = 0;
        if (p < r) {
            auto q = (p + r) / 2;
            tot_sum += merge_sort<T, R>(inputs, p, q);
            tot_sum += merge_sort<T, R>(inputs, q + 1, r);
            tot_sum += merge<T, R>(inputs, p, q, r);
            //cout << BOLDMAGENTA << "FINAL INVERSION FOUND " << tot_sum << YELLOW << "\n";
        }
        return tot_sum;
    }
}

template<typename T, typename R>
R count_inversion_merge_sort(std::vector<T> &inputs)
{
    return cpstl::merge_sort<T, R>(inputs, 0, inputs.size() - 1);
}

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for (size_t i = 0; i < n; ++i)
        cin >> sequence[i];
    return sequence;
}

int main() {
    string blank;
    size_t n_tests;
    cin >> n_tests;

    for (size_t i = 0; i < n_tests; ++i) {
        size_t n;
        cin >> n;
        std::vector<int> A = get_input_sequence<int>(n);
        long n_invs = count_inversion_merge_sort<int, long>(A);
        cout << n_invs << endl;
    }

    return 0;
}