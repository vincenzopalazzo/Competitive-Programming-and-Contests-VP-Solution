## [Longest Common Subsequence](https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: |
--- | --- | --- |
:heavy_check_mark:  | [Dynamic Programming](https://practice.geeksforgeeks.org/viewSol.php?subId=f6b98259be37a2a0a2f2514528cb05db&pid=701429&user=vpalazzo1) | 0.01 ms |

## Solution or Solution discussion

The solution use the dynamic programming and a matrix to memorize the value, an example
of matrix is the following.

Give Two String 'abcdaf' and 'acbcf' we need to feel the matrix in the following way

```
      a | b | c | d | a | f
  0 | 0 | 0 | 0 | 0 | 0 | 0
- - | - | - | - | - | - | -
a 0 | 1 | 1 | 1 | 1 | 1 | 1
- - | - | - | - | - | - | -
c 0 | 1 | 1 | 2 | 2 | 2 | 2
- - | - | - | - | - | - | -
b 0 | 1 | 2 | 2 | 2 | 2 | 2
- - | - | - | - | - | - | -
c 0 | 1 | 2 | 3 | 3 | 3 | 3
- - | - | - | - | - | - | -
f 0 | 1 | 2 | 3 | 3 | 3 | 4
```

The algorithm to feel the matrix with two for loop to scan the matrix and the the value
in position (i, j) is choose from the `std::max(matrix[i - i][j], matrix[i][j - i])`.
So the value is chose with the max of the value in the previous row and the max in the previus colum.
The length of max common subsequence is at the position `matrix[N][M]`

The space complexity is O(N^2) if the length of the string is the same of O(N*M) where N and M are the length of the inputs strings.

The time complexity is O(N*M) where the N and M again are the lengths of the strings.
