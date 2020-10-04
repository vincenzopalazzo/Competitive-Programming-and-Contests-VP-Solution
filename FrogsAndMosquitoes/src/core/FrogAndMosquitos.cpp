//
// Created by vincent on 9/14/20.
//
#include "FrogAndMosquitos.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool can_eat_mosquito(Frog &frog, Mosquito &mosquito)
{
    return !mosquito.dead && (frog.position == mosquito.position || frog.length_tongue >= mosquito.position - frog.position);
}

void eat_mosquitoes(std::vector<Frog> &frogs, std::vector<Mosquito> &mosquitoes) {
    sort(frogs.begin(), frogs.end(), [](Frog &a, Frog &b) {
        return a.position <= b.position;
    });
    sort(mosquitoes.begin(), mosquitoes.end(), [](Mosquito &a, Mosquito &b) {
        return a.position <= b.position;
    });

    //Draft solution
    //The problem to check are, how managed the mosquitoes if the frog can eat all mosquitoes.

    /**
     * The bug can be the following assertion, in some cases
     * the frog can continue to eat a lot of mosquitoes
     * Each mosquito is landing to the coordinate axis only after frogs eat all possible mosquitoes landed before. Mosquitoes are given in order of their landing to the coordinate axis.
     */
    for (int i = 0; i < frogs.size(); i++) {
        for (int j = i; j < mosquitoes.size(); j++) {
            if (can_eat_mosquito(frogs.at(i), mosquitoes.at(j))) {
                mosquitoes.at(j).dead = true;
                frogs.at(i).mosquito_eaten++;
                frogs.at(i).length_tongue += mosquitoes.at(j).dimension;
            }
        }
    }
}
