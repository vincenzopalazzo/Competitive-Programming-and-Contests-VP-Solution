//
// Created by vincent on 9/14/20.
//
#include <iostream>
#include <cstdlib>
#include "core/FrogAndMosquitos.h"

int main(int argc, char* argv[]){
    std::vector<Frog> frogs;
    std::vector<Mosquito> mosquito;

    //Example
    frogs.emplace_back(10, 2);
    frogs.emplace_back(15, 0);
    frogs.emplace_back(6, 1);
    frogs.emplace_back(0, 1);

    mosquito.emplace_back(110, 10);
    mosquito.emplace_back( 1, 1);
    mosquito.emplace_back( 6, 0);
    mosquito.emplace_back(15, 10);
    mosquito.emplace_back(14, 100);
    mosquito.emplace_back(12, 2);

    eat_mosquitoes(frogs, mosquito);

    for (auto frog : frogs) {
        std:: cout << "Frog: eat=" << frog.mosquito_eaten << " " << " tongue=" << frog.length_tongue << " pos=" << frog.position << std::endl;
    }
    return EXIT_SUCCESS;
}