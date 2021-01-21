## [Longest Bitonic subsequence](https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: | 
--- | --- | --- | 
:heavy_check_mark:  | [Dynamic Programming](https://practice.geeksforgeeks.org/viewSol.php?subId=68e2b4d515cb29f4ed1d1864c656f372&pid=704595&user=vpalazzo1) | 0.04 ms | 

## Solution or Solution discussion

The solution proposed inside this section use the dinamic programming and the solution
proposed to find the Longest increasing subsequence proposed in one of the previous problem
([Longest increasing subsequence](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/LongestIncreasingSubsequence/)).
In this case is found the longest increasing subsequence from left to right and from right to left, and the result 
is calculate to fid the maximum element between the two vector calculate with the Longest increasing subsequence algorithms.

The time complexity of the solution is O(N^2) and the space complexity is O(2*N) because 
we need to store two additional array to store the Longest increasing subsequence and the reverse calculation of it.