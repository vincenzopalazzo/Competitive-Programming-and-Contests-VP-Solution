/**
 * Segment tree data structure implementation
 * Copyright (C) 2020  Vincenzo Palazzo vincenzopalazzodev@gmail.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include <cstdlib>
#include <vector>
#include "TestTool.hpp"
#include "../core/MaxSum.h"

using namespace std;

void TEST_CASE_ONE()
{
    auto root = new Node<int>(3);
    auto four = new Node<int>(4);
    root->left = four;
    auto five = new Node<int>(5);
    root->right = five;
    auto double_for = new Node<int>(4);
    four->right = double_for;
    auto neg_ten = new Node<int>(-10);
    four->left = neg_ten;
    int max_sum_path = max_path_sum(root);

    cpstl::assert_equal("TEST_CASE_ONE", 16, max_sum_path);
}

void TEST_CASE_TWO()
{
    auto root = new Node<int>(3);
    int max_sum_path = max_path_sum(root);

    // Path don't exist
    cpstl::assert_equal("TEST_CASE_TWO", INT32_MIN, max_sum_path);
}

void TEST_CASE_TREE()
{
    auto root = new Node<int>(3);
    auto four = new Node<int>(4);
    root->left = four;
    int max_sum_path = max_path_sum(root);
    // Path don't exist
    cpstl::assert_equal("TEST_CASE_TREE", INT32_MIN, max_sum_path);
}

void TEST_CASE_FOUR()
{
    auto root = new Node<int>(3);
    auto four = new Node<int>(4);
    root->left = four;
    auto five = new Node<int>(5);
    root->right = five;
    int max_sum_path = max_path_sum(root);
    cpstl::assert_equal("TEST_CASE_FOUR", 3 + 5 + 4, max_sum_path);
}

void TEST_CASE_FIVE()
{
    auto root = new Node<int>(-9);
    auto four = new Node<int>(6);
    root->left = four;
    auto five = new Node<int>(-10);
    root->right = five;
    int max_sum_path = max_path_sum(root);

    cpstl::assert_equal("TEST_CASE_FIVE", -13, max_sum_path);
}

void TEST_CASE_SIX()
{
    auto root = new Node<int>(-10);
    auto four = new Node<int>(-1);
    root->left = four;
    auto five = new Node<int>(0);
    root->right = five;
    auto node = new Node<int>(3);
    four->left = node;
    int max_sum_path = max_path_sum(root);

    cpstl::assert_equal("TEST_CASE_SIX", -8, max_sum_path);
}

int main()
{
    TEST_CASE_ONE();
    TEST_CASE_TWO();
    TEST_CASE_TREE();
    TEST_CASE_FOUR();
    TEST_CASE_FIVE();
    TEST_CASE_SIX();
    return EXIT_SUCCESS;
}