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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */
#include "../test/Utils.hpp"
#include <cstdlib>
#include <string>
#include <vector>

const cpstl::Log LOG(true);

enum Role {
  MANAGER,
  DEVELOPER,
  NONE,
};

template<typename T>
struct Developer {
  std::string company;
  T bonus;
  T skill_factor;
  std::vector<std::string> skills;

  Developer(std::string &company, T bonus, T skill_factor, std::vector<std::string> skills):
    company(company), bonus(bonus), skill_factor(skill_factor), skills(skills) {}
};

template<typename T>
struct Manager {
  std::string company;
  T bonus;

  Manager(std::string company, T bonus): company(company), bonus(bonus) {}
};

struct OfficeFloor {
  std::size_t width;
  std::size_t height;
  std::vector<std::vector<Role>> office;

  OfficeFloor(){}

  OfficeFloor(std::size_t width, std::size_t height) {
    this->width = width;
    this->height = height;
    office = std::vector<std::vector<Role>>(width, std::vector<Role>(height, Role::NONE));
  }
};

// write the solution, but before I need to set understand what it the best way to
// to manage the data. For the moment I'm thinking to work with the followng data
// <OfficeFloor, Manager(s), Developer(s)> but the only problem that I have node is to
// if the OfficeFloor contains also the developer inside and we have the data about that.
template <typename T> static
void solution(OfficeFloor floor,
              std::vector<Developer<T>> developers,
              std::vector<Manager<T>> managers)
{

}
