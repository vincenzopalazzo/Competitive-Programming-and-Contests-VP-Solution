//
// Created by vincent on 9/14/20.
//
#ifndef SPYCBLOCK_SOLTEST_H
#define SPYCBLOCK_SOLTEST_H

#include <cstdlib>
#include <string>
#include <vector>

struct Frog {
    int length_tongue;
    int position;
    int mosquito_eaten;

    Frog(int position, int lengthTongue){
        this->length_tongue = lengthTongue;
        this->position = position;
        this->mosquito_eaten = 0;
    }
};

struct Mosquito {
    int position;
    int dimension;
    bool dead = false;

    Mosquito(int position, int dimension){
        this->dimension = dimension;
        this->position = position;
    }
};

/**
 * The idea is to use a counting sort idea, inparticular use the 2 sorted array by position
 * and check if the frog can eat the mosquito.
 *
 * 1. Order array by position
 * 2. Check if the mosquito can be eat from frog.
 */
void eat_mosquitoes(std::vector<Frog> &frogs, std::vector<Mosquito> &mosquitoes);

#endif //SPYCBLOCK_SOLTEST_H
