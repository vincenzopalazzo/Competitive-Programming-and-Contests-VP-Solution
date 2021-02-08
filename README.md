# Competitive-Programming-and-Contests-Solution

This repository contains the solution about the problems proposed at the Course of [Competitive Programming](https://github.com/rossanoventurini/CompetitiveProgramming)
by University of Pisa.

## Table of Content

- Introduction
- Built with
- Problems with a briefly discussion about them
- How build the solutions
- How contribute
- License

## Introduction

Each solution is provided with a battery of unit tests and a code structure under the src directory looks like the following tree:

- src
    - test
      - *Main.cpp*: Tests units where is possible test the solution in local with the test result on console.
      - **.hpp*: A couple of file to implement the test tools, implemented inside the repository [cpstl](https://vincenzopalazzo.github.io/cpstl/)
    - core
      - *SolutionName.hpp*: file that contains the solution of the problem
      - One or more data structure file implemented inside the repository [cpstl](https://vincenzopalazzo.github.io/cpstl/)
    - *MainSite.cpp*: The file that contains the solution for the online judge
    - *CMakeFile*

Some solutions are provided with different implementation (where is present or covered from the developer) with complete benchmarks developed with [Google benchmark](https://github.com/google/benchmark).
The result are stored inside a JSON or a CVS file called *result* and the machine where there are ran has the following characteristic.

- OS: Linuxmint 20.1 ulyssa
- CPU: Intel Core i5-6300U @ 4x 3GHz
- RAM: 16 GB.

Some of these benchmarks have a complete discussion with the Jupiter Notebook, see last colum of the tables below.

> If you want run the benchmark on your own computer and your computer are a personal computer, in some cases you need to disable some machine setting, but you can following
[this answer](https://stackoverflow.com/a/48110959/10854225) on StackOverflow (If you are using a linux machine)

## Built with

All the solutions are developed with C++ STD, and also with a couple of external tools reported below:

- [CPSTL](https://vincenzopalazzo.github.io/cpstl): Competitive Programming Standard "library", it is a new project with the object to include a complete collection of algorithms and data structure to use in the Competitive Programming problem. Also it is open to support different programming language.
- [Google benchmark](https://github.com/google/benchmark): A Google framework to make cool micro benchmarks, you need to install it if you want run the benchmarks in some problem, othewise you can avoid to install it.

## Problems with a briefly discussion about them

Name | Solved | Repository | Report |
--- | --- | --- | --- |
*Leaders in array* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/LeadersInArray) | _ |
*Kadane's algorithm* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/KadanesAlgorithm) | _ |
*Missing number in array* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/MissingNumberInArray) | _ |
*Trapping rain water* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/TrappingRainWater) | _ |
*Sliding window maximum* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/SlidingWindowMaximum) | [Class Report](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/SlidingWindowMaximum/benchmark/docs) |
*Next larger element* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/NextLargerElement) | _ |
*Towers* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Towers) | _ |
*Finding Team Member* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/FindingTeamMember) | _ |
*The Monkey and the Oiled Bamboo* | :heavy_check_mark:  | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/MonkeyAndBamboo) | _ |
*Inversion count* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/InversionCounting) | _ |
*Two Types of Spells* | _ | [Code]() | _ |
*Frogs and Mosquitoes* | _ | [Code]() | _ |
*Maximum path sum* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/MaximumPathSumBetween2LeafNodes) | _ |
*Longest k Good Segment* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/LongestkGoodSegment) | _ |
*Ilya and Queries* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/IlyaAndQueries) | _ |
*Number of ways* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/NumberOfWays) | _ |
*Little girl and maximum sum* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/LittleGirlandMaximumSum) | _ |
*Update the array* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/UpdateTheArray) | _ |
*Nested segments (also segment tree)* | 3/3 :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/NestedSegments) | _ |
*Pashmak and Parmida's problem* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/PashmakAndParmida) | _ |
*Circular RMQ* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/CircularRMQ) | [Benchmarks](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/CircularRMQ/benchmark/results/CircularRMQ_benchmark/) |
*Triplets* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Triplets) | _ |
*Smaller Values* | 1/3 :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/SmallerValues) | _ |
*Powerful array* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/PowerfulArray) | _ |
*Tree and queries* | | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/) | _ |
*Longest common subsequence* | :heavy_check_mark:  | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/LongestCommonSubsequence) | _ |
*Minimum number of jumps* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/MinimumNumberOfJumps) | _ |
*Subset sum* | 4/4 :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/PartitionEqualSubsetSum) | _ |
*0-1 knapsack* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/01knapsack) | _ |
*Longest increasing subsequence* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/LongestIncreasingSubsequence) | _ |
*Longest bitonic subsequence* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/LongestBitonicSubsequence) | _ |
*Edit distance* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/EditDistance) | _ |
*Vertex cover* | | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/) | _ |
*Longest palindromic subsequence* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/LongestPalindromicSubsequence) | _ |
*N meetings in one room* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/NMeetingsInOneRoom) | _ |
*Magic numbers* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/MagicNumbers) | _ |
*Wilbur and array* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/WilburAndArray) | _ |
*Alternativ e thinking* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/AlternativeThinking) | _ |

## Segment Tree report

During the Courses is developed also a small paper to introduce the Segment tree by Examples. ["Segment Tree: A Complete Introduction by Examples"](https://gitlab.com/vincenzopalazzo/competitiveprogrammingreport/uploads/b2dcff843e34eedfab80fb737126b465/report.pdf)

## Report Experiments

Name | Solved | Repository | Report |
--- | --- | --- | --- |
*RMQ* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/report_experiment/RMQ) | [Benchmarks](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/report_experiment/RMQ/benchmark/results/RMQ_benchmark) |
*Circular RMQ* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/CircularRMQ) | [Benchmarks](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/CircularRMQ/benchmark/results/CircularRMQ_benchmark/) |
*Kth Zero* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/report_experiment/FindKthZero) | _ |
*MKTHNUM* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/report_experiment/MKTHNUM) | [Benchmarks](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/report_experiment/MKTHNUM/benchmark/result/MKTHNUM_benchmark) |
*Range Updates and Sums* | :construction: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/report_experiment/RangeUpdatesSums/) | _ |


## Appendix

Name | Solved | Repository |
--- | --- | --- |
*DQUERY* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/extra/DQUERY) |
*FibonacciNum* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/extra/FibonacciNum) |
*ClotestValueOnBST* | :construction: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/extra/ClotestValueOnBST) |
*TwoNumberSum* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/extra/TwoNumberSum) |

#### Google kikstart 2020

Name | Solved | Repository |
--- | --- | --- |
*Allocation* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/google_kikstart/roundA_2020_Allocation) |
*Plates* | :construction: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/google_kikstart/roundA_2020_Plates) |

## How build the solutions

Each solution contains a complete test unit developed with a Test tools developed adhock as a "Copy and Paste" code, and to build the project to ran the
test the following commands are required

```bash
>> mkdir build && cd build
>> cmake .. && make
>> ./NameSolution
```

One possible output is reported below

```bash
|------------ TEST TEST_CASE_ONE_SEGMENT_TREE -------------------|
TEST_CASE_ONE_SEGMENT_TREE PASSED
|------------ TEST TEST_CASE_ONE_LAZY_SEGMENT_TREE -------------------|
TEST_CASE_ONE_LAZY_SEGMENT_TREE PASSED
|------------ TEST TEST_CASE_TWO_LAZY_SEGMENT_TREE -------------------|
TEST_CASE_TWO_LAZY_SEGMENT_TREE PASSED
|------------ TEST TEST_CASE_THREE_LAZY_SEGMENT_TREE -------------------|
TEST_CASE_THREE_LAZY_SEGMENT_TREE PASSED
```

## How contribute

The repository is open to receive contribution to improve solutions or the quality of the repository, there are only a few rules to respect that are reported
below.

- Each solution need to start with the C++ template project, available [here](https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution/tree/master/template)
- Each code that is inside the repository need to follow the good formatted code guide lines, so if the solution uses the C++ classes the Google code style need to be included in the solution. _clang-format_ file available [at the following link](https://github.com/vincenzopalazzo/cpstl/blob/master/.clang-format), otherwise is the C++ is without classes a Linux Kernel guide lines need to
be included _clang-format_ file available [at the following link](https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution/blob/master/template/.clang-format).
- New implementation of datastructure need to be push also in repository [cpstl](https://vincenzopalazzo.github.io/cpstl/).
- Each solution, need to contains a Readme with some details about the implementation and the time execution on the online Judge, one
example can be the following [solution](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/extra/FibonacciNum/)
- Have fun.

## License

<div align="center">
  <img src="https://opensource.org/files/osi_keyhole_300X300_90ppi_0.png" width="150" height="150"/>
</div>

Copyright (c) 2021 Vincenzo Palazzo vincenzopalazzodev@gmail.com and 
all the professor of the class Competitive Programming and Contest
https://github.com/rossanoventurini/CompetitiveProgramming

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
