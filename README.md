# Competitive-Programming-and-Contests-Solution

This repository contains the solution about the problems proposed at the Course of [Competitive Programming](https://github.com/rossanoventurini/CompetitiveProgramming)
by University of Pisa.

## Table of Content

- [Introduction](https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution#introduction)
- [Built with](https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution#built-with)
- [Problems with a briefly discussion about them](https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution#problems-with-a-briefly-discussion-about-them)
- [How contribute](https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution#how-contribute)
- [License](https://github.com/vincenzopalazzo/Competitive-Programming-and-Contests-VP-Solution#license)

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

TODO

> If you want run the benchmark on your own computer and your computer are a personal computer, in some cases you need to disable some machine setting, but you can following
[this answer](https://stackoverflow.com/a/48110959/10854225) on StackOverflow (If you are using a linux machine)

## Built with

All the solutions are developed with C++ STD, and also with a couple of external tools reported below:

- [CPSTL](): Competitive Programming Standard library, it is a new project that include a collection of algorithms and data structure for competitive programming in different language.
- [Google benchmark](): A Google framework to make cool code benchmark, you need to install it if you want run the benchmarks in some problem, othewise you can avoid to install it.
- [abseil-cpp](https://github.com/abseil/abseil-cpp): TODO I'm not sure that I introduce this library at the moment.

## Problems with a briefly discussion about them

Name | Solved | Repository | Report |
--- | --- | --- | --- |
*Leaders in array* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/LeadersInArray) | _ |
*Kadane's algorithm* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/KadanesAlgorithm) | _ |
*Missing number in array* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/MissingNumberInArray) | _ |
*Trapping rain water* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/TrappingRainWater) | _ |
*Sliding window maximum* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/SlidingWindowMaximum) | [Report](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/SlidingWindowMaximum/benchmark/docs) |
*Next larger element* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/NextLargerElement) | _ |
*Towers* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/NextLargerElement) | _ |
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
*Longest bitonic subsequence* | | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/) | _ |
*Edit distance* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/EditDistance) | _ |
*Vertex cover* | | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/) | _ |
*Longest palindromic subsequence* | | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/) | _ |
*N meetings in one room* | | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/) | _ |
*Magic numbers* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/MagicNumbers) | _ |
*Wilbur and array* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/WilburAndArray) | _ |
*Alternativ e thinking* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/AlternativeThinking) | _ |

## Segment Tree report

During the Courses was developed also a report, with the title ["Segment Tree: A Complete Introduction by Examples"](#TODO)

## Appendix

Name | Solved | Repository | Report |
--- | --- | --- | --- |
*RMQ* | :heavy_check_mark: | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/report_experiment/RMQ) | [Benchmarks](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/report_experiment/RMQ/benchmark/results/RMQ_benchmark) |
*Find Kth Zero* | _ | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/report_experiment/FindKthZero) | [Benchmarks](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/) |
*KQUERY* | _ | [Code](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/Appendix/report_experiment/KQUERY) | [Benchmarks](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/) |

## How contribute

## Conclusion

## License

<div align="center">
  <img src="https://opensource.org/files/osi_keyhole_300X300_90ppi_0.png" width="150" height="150"/>
</div>

Copyright (c) 2021 Vincenzo Palazzo vincenzopalazzodev@gmail.com

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
