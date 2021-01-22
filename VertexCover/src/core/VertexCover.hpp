/**
 * Competitive-Programming-and-Contests-VP-Solution a collection of
 * code with an engineering approach to solve the problem.
 * https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution
 *
 * Copyright (C) 2020-2021  Vincenzo Palazzo vincenzopalazzodev@gmail.com
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
#include <string>
#include <vector>
#include "../test/Utils.hpp"

const cpstl::Log LOG(true);

template <typename T>
struct Node {
  T value;
  Node<T> *left;
  Node<T> *right;

  Node (Node<T> *left, Node<T> *right, T value):
    left(left), right(right), value(value){}

  Node (T value):
    left(nullptr), right(nullptr), value(value) {}

  bool is_leaf() {
    return left == nullptr && right == nullptr;
  }
};


template <typename T>
static T number_of_vertex_in_the_tree(Node<T> *root)
{
  if(!root) return 0;
  if (root->is_leaf()) return 0;

  auto with_root = 1 + number_of_vertex_in_the_tree<T>(root->left)
                             + number_of_vertex_in_the_tree<T>(root->right);

  auto without_root = 0;

  if (root->left)
    without_root += 1 + number_of_vertex_in_the_tree<T>(root->left->left) + number_of_vertex_in_the_tree<T>(root->left->right);
  if(root->right)
    without_root += 1 + number_of_vertex_in_the_tree<T>(root->right->left) + number_of_vertex_in_the_tree<T>(root->right->right);

  return std::min(with_root, without_root);
}
