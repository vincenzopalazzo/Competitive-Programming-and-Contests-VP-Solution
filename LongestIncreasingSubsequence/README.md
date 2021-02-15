## [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: |
--- | --- | --- |
:heavy_check_mark:  | [Dynamic Programming](#TODO) | ? ms |
:heavy_check_mark:  | [Dynamic Programming With MEM.](https://leetcode.com/submissions/detail/456328869/) | 272 ms |
:heavy_check_mark:  | [Dynamic Programming With MEM + Binary Search](https://leetcode.com/submissions/detail/456328071/) | 8 ms |

## Solution or Solution discussion

The basic idea to solve this problem is to feel the array that contains the element greater than the element in position i.
An at the end the algorithm finds the maximum element inside the array.
The time complexity of this solution is O(N ^ 2) and the space complexity is O(N) because only an additional array of size N is needed.

However, the solution can be improved with a solution in time complexity equal to O(N log N), with a simple observation reported inside [this
stack overflow post](https://stackoverflow.com/a/2631810/10854225). The basic idea is to maintain a set (Binary Search Tree) with all the elements
of the original array, and when a new element enters inside the set, this element needs to be the last, otherwise, all the elements greater than the last element
insert inside the set are removed.

An example can be the following input sequences `[2, 6, 3, 4, 1, 2, 9, 5, 8]` with the following execution

```bash
0. S = {} - Initialize S to the empty set
1. S = {2} - New largest LIS
2. S = {2, 6} - New largest LIS
3. S = {2, 3} - Changed 6 to 3
4. S = {2, 3, 4} - New largest LIS
5. S = {1, 3, 4} - Changed 2 to 1
6. S = {1, 2, 4} - Changed 3 to 2
7. S = {1, 2, 4, 9} - New largest LIS
8. S = {1, 2, 4, 5} - Changed 9 to 5
9. S = {1, 2, 4, 5, 8} - New largest LIS
```

The solution tested on the site geeksforgeeks was the solution inside the LongestIncreasingSubsequence.h file because with the new version
of the side, there is no longer available the opportunity to read the input with a normal program but we need to write a method that is on the
site.

At the moment my implementation for this site used the DP with memorization technique with the following implementation

```c++
int longestSubsequence(int n, int a[])
{
    std::vector<int> mem(n, 1);
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                mem[i] = std::max(mem[i], mem[j] + 1);
            }
        }
    }
    int lis = mem[0];
    for (std::size_t i = 0; i < n; i++) {
        lis = std::max(lis, mem[i]);
    }
    return lis;
}
```
