//
// Created by vincent on 9/14/20.
//
#include "MaxSubArrayPos.h"

#include <vector>

using namespace std;


//What is the computation time?
//I can do better? Yes, it is the first method. TODO implement the second method!
vector<int> find_max_sub_array_pos(const int input[], const int &size_array, const int &k)
{
    vector<int> max_values;
    for(int i = 0; i <= size_array - k; i++){
        int max_val = input[i];
        for(int j = 1; j < k; j++){
            if(max_val < input[i + j]){
                max_val = input[i + j];
            }
        }
        max_values.push_back(max_val);
    }
    return max_values;
}

