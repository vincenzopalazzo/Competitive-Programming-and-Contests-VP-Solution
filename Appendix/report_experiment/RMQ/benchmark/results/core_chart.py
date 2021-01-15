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

def make_naive_benchmark_chart():
    labels = []
    times = []
    for bm in bm_json["benchmarks"]:
        if "BM_NAIVE_SOLUTION" in bm["name"]:
            labels.append('Q: {}'.format(bm['run_name'].split('/')[1]))
            times.append(bm["real_time"])
    fig = pandas.DataFrame({
    'RMQ naive': times,
    }, index=labels)
    fig.plot.bar(rot=0, figsize=(20,5), logy=True)

def make_segment_tree_and_naive_benchmark_chart():
    labels = []
    times_naive = []
    times_segment = []
    for bm in bm_json["benchmarks"]:
        if "BM_NAIVE_SOLUTION" in bm["name"]:
            labels.append('Q: {}'.format(bm['run_name'].split('/')[1]))
            times_naive.append(bm["real_time"])
        elif "BM_SEGMENT_TREE_BH" in bm["name"]:
            times_segment.append(bm["real_time"])

    stl = pandas.DataFrame({
    'RMQ naive': times_naive,
    'RMQ Segment Tree': times_segment
    }, index=labels)
    stl.plot.bar(rot=0, figsize=(20,5), logy=True)

def make_segment_tree_lazy_segment_treee_benchmark_chart():
    labels = []
    times_lazy = []
    times_segment = []
    for bm in bm_json["benchmarks"]:
        if "BM_LAZY_SEGMENT_TREE_BH" in bm["name"]:
            labels.append('Q: {}'.format(bm['run_name'].split('/')[1]))
            times_lazy.append(bm["real_time"])
        elif "BM_SEGMENT_TREE_BH" in bm["name"]:
            times_segment.append(bm["real_time"])

    stl = pandas.DataFrame({
    'RMQ Lazy Propagation': times_lazy,
    'RMQ Segment Tree': times_segment
    }, index=labels, )
    stl.plot.bar(rot=0, figsize=(20,5), logy=True)
