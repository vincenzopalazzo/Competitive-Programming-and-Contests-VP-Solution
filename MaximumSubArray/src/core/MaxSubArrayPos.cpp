//
// Created by vincent on 9/14/20.
//
#include "MaxSubArrayPos.h"

#include <iostream>
#include <vector>

using namespace std;

vector<int> find_max_sub_array_pos(const int input[9], const int &size_array, const int &k)
{
    vector<int> max_values;
    int max_val = 0;
    int index_sub_arr = 0;
    for(int i = 0; i < size_array; i++){
        if(index_sub_arr < k){
            index_sub_arr++;
            if(max_val < input[i])
                max_val = input[i];
        }else{
            //k > sub array simension
            index_sub_arr = 0;
            max_values.push_back(max_val);
            max_val = 0;
        }
    }
    return max_values;
}

