## [Problem title](https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56)

- Status: Completed :heavy_check_mark: 

Solved | Solution | Time :clock11: | 
--- | --- | --- | 
:heavy_check_mark:   | _ | _ ms | 

## Solution 

The solution has a cost O(N) in terms on time and O(N) in terms of Space.

The procedure to solve the problem is:

- Sort the array in the increase order
- Iterate for each element and check if you can buy the home.


## Problem
There are N houses for sale. The i-th house costs Ai dollars to buy. You have a budget of B dollars to spend.

_What is the maximum number of houses you can buy?_

### Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a single line containing the two integers N and B. The second line contains N integers. The i-th integer is Ai, the cost of the i-th house.

### Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum number of houses you can buy.

### Limits
- Time limit: 15 seconds per test set.
- Memory limit: 1GB.
- 1 ≤ T ≤ 100.
- 1 ≤ B ≤ 105.
- 1 ≤ Ai ≤ 1000, for all i.

- Test set 1
    - 1 ≤ N ≤ 100.
- Test set 2
    - 1 ≤ N ≤ 105.