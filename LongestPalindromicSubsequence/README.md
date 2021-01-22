## [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/submissions/)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: |
--- | --- | --- |
:heavy_check_mark:  | [Dynamic Programming (O(N^2))](https://leetcode.com/submissions/detail/446297759/) |  TLE  |
:heavy_checl_mark:  | [Dynamic Programming (O(N))](https://leetcode.com/submissions/detail/446302755/)    | 56 ms |

## Solution or Solution discussion

### Dynamic Programming O(n^2)

The solution with dynamic programming proposed in this section use the recursion to find the
result of the problme, and the recusion look like

- i = j : return 1 because the character are the same element;
- string[i] == string[j] and i + 1 = j: return 2, the character are consecutive duplicate (aa,bb)
- string[i] != string[j]: get the maximum result and skip the element to the right or the element to the left.

### Dynamic Programming O(N) exstra space (With memorizzation)

To improve the solution we ca use a bottom up solution with the memorization technique based on the previus recursion, that save time complexity of the algorithm. It solution reduce the space complexity from O(N^2) to O(N) and it store the result inside an array.

The solution of the problem is in the last position of the array.
