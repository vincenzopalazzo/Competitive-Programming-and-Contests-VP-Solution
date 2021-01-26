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

const cpstl::Log LOG(false);

template<typename T>
struct Meeting {
	T start_time;
	T end_time;
	std::size_t index;
	Meeting(T start, T end, std::size_t at):
		start_time(start), end_time(end), index(at){}
};

template <typename T>
static std::vector<T> make_scheduling_meeting(std::vector<Meeting<T>> &meetings)
{
	std::vector<T> result;
	if(meetings.empty()) return result;
	std::sort(meetings.begin(), meetings.end(), [](auto meeting_a, auto meeting_b) {
		return meeting_a.end_time < meeting_b.end_time;
	});

	result.push_back(meetings[0].index + 1);

	auto time_limit = meetings[0].end_time;

	for (std::size_t i = 1; i < meetings.size(); i++) {
		auto meeting = meetings[i];
		if (meeting.start_time > time_limit) {
			result.push_back(meeting.index + 1);
			time_limit = meeting.end_time;
		}
	}
	return result;
}
