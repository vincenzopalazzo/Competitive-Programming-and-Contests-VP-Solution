//
// Created by vincent on 9/14/20.
//
#include "CountTriples.h"
#include <iostream>

using namespace std;

template <typename T, typename R>
R count_triples_trivial(std::vector<T> const &inputs)
{
    R triples = 0;
    for (int i = 0; i < inputs.size(); i++) {
        for (int j = i + 1; j < inputs.size(); j++) {
            for (int z = j + 1; z < inputs.size(); z++) {
                if (inputs[i] < inputs[j] < inputs[z]) {
                    triples++;
                }
            }
        }
    }
    return triples;
}

template int count_triples_trivial(std::vector<int> const &inputs);
