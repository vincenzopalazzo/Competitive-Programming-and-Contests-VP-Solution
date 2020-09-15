//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include "core/MaxSubArrayPos.h"

using namespace std;

void print_function(const int input[9], const vector<int> &result, const int &k){
    int index = 0;
    vector<int> sub_array;
    int index_result = 0;
    for(int i = 0; i < 9; i++){
        if(index < k){
            index++;
            sub_array.push_back(input[i]);
        }else{
            index = 0;
            cout << "Array: ";
            for(int j = 0; j < sub_array.size(); j++){
                cout << sub_array.at(j);
            }
            cout << "\nWith max element: " << result.at(index_result) << endl;
            index_result++;
            sub_array.clear();
        }
    }
}

int main(int argc, char* argv[]){
    int input[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    const int size_array = 9;
    vector<int> result = find_max_sub_array_pos(input, size_array, k);
    print_function(input, result, k);
    return EXIT_SUCCESS;
}
