//
// Created by vincent on 9/14/20.

#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "LazySegmentTree.h"

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

bool can_eat_mosquito(Frog &frog, Mosquito const &mosquito)
{
    return !mosquito.dead && (frog.position == mosquito.position || frog.length_tongue >= (mosquito.position - frog.position));
}

/**
 * The idea is to use a counting sort idea, in particular use the 2 sorted array by position
 * and check if the frog can eat the mosquito.
 *
 * 1. Order array by position
 * 2. Check if the mosquito can be eat from frog.
 */

void eat_mosquitoes_naive(std::vector<Frog> &frogs, std::vector<Mosquito> &mosquitoes)
{
    /*std::sort(frogs.begin(), frogs.end(), [](Frog &a, Frog &b) {
        return a.position <= b.position;
    });*/
    std::sort(mosquitoes.begin(), mosquitoes.end(), [](Mosquito &a, Mosquito &b) {
        return a.position <= b.position;
    });

    /**
     * The bug can be the following assertion, in some cases
     * the frog can continue to eat a lot of mosquitoes
     * Each mosquito is landing to the coordinate axis only after frogs eat all possible mosquitoes landed before.
     * Mosquitoes are given in order of their landing to the coordinate axis.
     */
    for (int i = 0; i < frogs.size(); i++) {
        int j = 0;
        while (i < frogs.size() && !mosquitoes.empty() && j < mosquitoes.size()) {
            auto mosquito = mosquitoes.at(j);
            if (can_eat_mosquito(frogs.at(i), mosquito)) {
                frogs.at(i).mosquito_eaten++;
                frogs.at(i).length_tongue += mosquito.dimension;
                mosquitoes.erase(std::next(mosquitoes.begin(), j));
                continue;
            }
            j++;
        }
    }
}

void eat_mosquitoes_set(std::vector<Frog> &frogs, std::set<Mosquito> &mosquitoes)
{
    /*std::sort(frogs.begin(), frogs.end(), [](Frog &a, Frog &b) {
        return a.position <= b.position;
    });*/
    std::sort(mosquitoes.begin(), mosquitoes.end(), [](Mosquito &a, Mosquito &b) {
        return a.position <= b.position;
    });

    /**
     * The bug can be the following assertion, in some cases
     * the frog can continue to eat a lot of mosquitoes
     * Each mosquito is landing to the coordinate axis only after frogs eat all possible mosquitoes landed before.
     * Mosquitoes are given in order of their landing to the coordinate axis.
     */
    for (int i = 0; i < frogs.size(); i++) {
        int j = 0;
        while (i < frogs.size() && !mosquitoes.empty() && j < mosquitoes.size()) {
            auto mosquito = mosquitoes.at(j);
            if (can_eat_mosquito(frogs.at(i), mosquito)) {
                frogs.at(i).mosquito_eaten++;
                frogs.at(i).length_tongue += mosquito.dimension;
                mosquitoes.erase(std::next(mosquitoes.begin(), j));
                continue;
            }
            j++;
        }
    }
}
