//
// Created by vincent on 10/21/20.
//

#include <cassert>
#include <iostream>
#include "Order.h"

using namespace std;

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
    template<typename T>
    T merge(vector<T> &inputs, size_t p, size_t q, size_t r)
    {
        assert(!inputs.empty());
        assert(p >= 0);
        assert(r >= 0);
        assert(q >= 0);

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
        T inversion = 0;
        int k = p;
        while (i < n1 && j < n2) {
            if (sub_arr_left[i] > sub_arr_right[j])
                inversion++;
            i++;
            j++;
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

        return inversion;
    }

    template<typename T>
    T merge_sort(vector<T> &inputs, size_t p, size_t r) {
        T tot_sum = 0;
        if (p < r) {
            auto q = (p + r) / 2;
            tot_sum += merge_sort(inputs, p, q);
            tot_sum += merge_sort(inputs, q + 1, r);
            tot_sum += merge(inputs, p, q, r);
        }
        return tot_sum;
    }
}

//Type declaration
template int cpstl::merge_sort<int>(vector<int> &inputs, size_t p, size_t r);

