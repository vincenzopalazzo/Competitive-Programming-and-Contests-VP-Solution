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
#include <bits/stdc++.h>

using namespace std;

int maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}// } Driver Code Ends


struct Meeting {
	int start_time;
	int end_time;
	std::size_t index;
	Meeting(int start, int end, std::size_t at):
		start_time(start), end_time(end), index(at){}
};

int maxMeetings(int start[], int end[], int n) {
    if (n == 0) return 0;

    std::vector<Meeting> meetings;
    meetings.reserve(n);
    for (int i = 0; i < n; i++) {
        meetings.emplace_back(start[i], end[i], i);
    }

	if(meetings.empty()) return 0;

	std::sort(meetings.begin(), meetings.end(), [](auto meeting_a, auto meeting_b) {
		return meeting_a.end_time < meeting_b.end_time;
	});

	auto time_limit = meetings[0].end_time;
    auto count = 1;
	for (std::size_t i = 1; i < meetings.size(); i++) {
		auto meeting = meetings[i];
		if (meeting.start_time > time_limit) {
			count++;
			time_limit = meeting.end_time;
		}
	}
	return count;

}
