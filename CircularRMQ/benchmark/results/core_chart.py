"""
Competitive-Programming-and-Contests-VP-Solution a collection of
code with an engineering approach to solve the problem.
https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution

Copyright (C) 2020-2021  Vincenzo Palazzo vincenzopalazzodev@gmail.com
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
"""

import pandas
import json
# %matplotlib inline
import matplotlib as mpl
import matplotlib.pyplot as plt
from IPython.display import display_html


mpl.style.use('ggplot')

result_json = open("../result.json", "r")
bm_json = json.loads(result_json.read())

def make_comparison_chart():
    labels = []
    times_lazy = []
    times_segment = []
    for bm in bm_json["benchmarks"]:
        if "RoundRMQSegmentTreeBM" in bm["name"]:
            labels.append('Q: {}'.format(bm['run_name'].split('/')[1]))
            times_segment.append(bm["real_time"])
        elif "RoundRMQLazySegmentTreeBM" in bm["name"]:
            times_lazy.append(bm["real_time"])

    stl = pandas.DataFrame({
    'CRMQ Lazy Propagation': times_lazy,
    'CRMQ Segment Tree': times_segment
    }, index=labels)
    stl.plot.bar(rot=0, figsize=(20,5), logy=True)
