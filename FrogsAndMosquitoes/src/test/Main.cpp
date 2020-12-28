//
// Created by vincent on 9/14/20.
//
#include <cstdlib>
#include <vector>
#include "../core/FrogAndMosquitos.h"
#include "Utils.hpp"
#include "TestTool.hpp"

using namespace std;

void TEST_CASE_ONE()
{
  std::vector<Frog> frogs;
  frogs.emplace_back(10, 2);
  frogs.emplace_back(15, 0);
  frogs.emplace_back(6, 1);
  frogs.emplace_back(0, 1);

  std::vector<Mosquito> mosquitoes;
  mosquitoes.emplace_back(110, 10);
  mosquitoes.emplace_back(1, 1);
  mosquitoes.emplace_back(6, 0);
  mosquitoes.emplace_back(15, 10);
  mosquitoes.emplace_back(14, 100);
  mosquitoes.emplace_back(12, 2);

  eat_mosquitoes_naive(frogs, mosquitoes);
  std::vector<int> result;
  result.reserve(frogs.size() * 2);
  for (auto frog: frogs) {
      result.push_back(frog.mosquito_eaten);
      result.push_back(frog.length_tongue);
  }
  cpstl::assert_equal("TEST_CASE_ONE", {3, 144, 1, 10, 1, 1, 1, 2}, result);
}

int main()
{
    TEST_CASE_ONE();
    return EXIT_SUCCESS;
}
