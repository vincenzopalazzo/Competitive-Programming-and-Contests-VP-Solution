## [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

- Status: Completed :heavy_check_mark: 

Solved | Solution | Time :clock11: | 
--- | --- | --- | 
:heavy_check_mark:  | [Source](#TODO) | 0.36 ms | 

## Solution or Solution discussion

The solution tested on the site geeksforgeeks was the solution inside the LongestIncreasingSubsequence.h file because with the new version
of the side there is no longer available the opportunity to read the input with a normal program but we need to write a method that is on the 
site.

At the moment my implementation for this site used the DP with memorization tecnique with the follow implementation

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