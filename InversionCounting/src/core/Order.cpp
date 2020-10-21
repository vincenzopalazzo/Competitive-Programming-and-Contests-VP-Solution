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
    int merge(vector<T> const &inputs, int p, int q, int r) {
        assert(!inputs.empty());
        assert(p >= 0);
        assert(r >= 0);
        assert(q >= 0);

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

//Type declaration
template int cpstl::merge_sort<int>(vector<int> const &inputs, int p, int r);

