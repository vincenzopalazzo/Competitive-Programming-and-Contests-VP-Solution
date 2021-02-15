## [Ilya and Queries](https://codeforces.com/problemset/problem/313/B)

- Status: Completed :heavy_check_mark: 

Solved | Solution | Time :clock11: | 
--- | --- | --- | 
:heavy_check_mark:  | [Prefix Sum](https://codeforces.com/contest/313/submission/107392354) | 184 ms | 

## Solution or Solution discussion

The solution uses the prefix sum technique to resolve the problem, in particular, it split the string into characters and create 
and intermedia vector that in position i has 1 if the string in position i-1 usi qual to the string in position i. Otherwise 0.

After that, a prefix sum operation is performed on the intermedia vector, and the query is performed on the prefix sum result.

The time and space complexity of the solution is O(N).