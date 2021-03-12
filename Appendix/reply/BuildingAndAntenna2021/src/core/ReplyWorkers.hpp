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

//TODO: I really need this?
struct Matrix {
	std::size_t width;
	std::size_t height;

	Matrix(std::size_t width, std::size_t height)
	    : width(width), height(height)
	{
	}
};

template <typename T> struct Building {
	std::size_t x_pos;
	std::size_t y_pos;
	T latency;
	T connection_speed;

	Building(std::size_t x_pos, std::size_t y_pos, T latency,
		 T connection_speed)
	    : x_pos(x_pos), y_pos(y_pos), latency(latency),
	      connection_speed(connection_speed)
	{
	}
};

template <typename T> struct Antenna {
	T range;
	T connection_speed;

	Antenna(T range, T connection_speed)
	    : range(range), connection_speed(connection_speed)
	{
	}
};

template <typename T>
static bool solution(std::vector<Building<T>> buildings,
		     std::vector<Antenna<T>> antennas, T rewars)
{
	return true;
}
