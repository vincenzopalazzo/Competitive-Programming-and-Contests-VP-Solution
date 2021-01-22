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
#include "TestTool.hpp"
#include "../core/VertexCover.hpp"

using namespace std;

void TEST_CASE_ONE()
{
	Node<int> *root = new Node<int>(20);
	root->left = new Node<int>(8);
	root->left->left = new Node<int>(4);
	root->left->right = new Node<int>(12);
	root->left->right->left = new Node<int>(10);
	root->left->right->right = new Node<int>(14);
	root->right = new Node<int>(22);
	root->right->right = new Node<int>(24);
	auto result = number_of_vertex_in_the_tree(root);
	cpstl::assert_equal("TEST_CASE_ONE", 3, result);
	delete root;
}

int main()
{
    TEST_CASE_ONE();
    return EXIT_SUCCESS;
}
