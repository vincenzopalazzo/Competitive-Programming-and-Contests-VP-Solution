//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include "core/MaxSubArrayPos.h"

using namespace std;

int main(int argc, char* argv[]){
    const int size_input = sizeof(argv)/sizeof(*argv);
    cout << "Input size: " << size_input << ".";
    for(int i = 0; i < size_input; i++){
        switch (i) {
            case 0: cout << "[" << argv[i] << ",";
                break;
            case size_input: cout << argv[i] << "]";
                break;
            default: cout << argv[i] << ",";
        }
    }

    return EXIT_SUCCESS;
}