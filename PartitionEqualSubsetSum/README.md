## [Partition Equal Subset Sum](https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1)

- Status: Working in progress :construction:

Solved | Solution | Time :clock11: |
--- | --- | --- |
:heavy_check_mark:  | [Naive Recursion](#TODO)     | TLE     |
:heavy_check_mark:  | [Dynamic Programming STL HASH Map](#TODO) | XXXX ms |
:heavy_check_mark:  | [Dynamic Programming Matrix](#TODO) | XXXX ms |
:heavy_check_mark:  | [Dynamic Programming Vector](https://practice.geeksforgeeks.org/viewSol.php?subId=2dbdd4fc132b4293991861abd8f58ca0&pid=704573&user=vpalazzo1) | 0.11 secs |

## Solution or Solution discussion

### Naive recursion

A naive solution can be to make a recusion call if the module 2 of the total sum of the element is 0, and check if the
sum exist by taking some decision, such that

- The actual element are taking (sum  + inputs[i])
- The actual element is skipped (sum)

and check if the sum * 2 == tot_sum of the elment inside the array, if yes true is returned from the algorithm otherwise false is returned.


### Optimize the Native recursion

From the naive recursion is possible notice that the algorithm with some inputs can make the sum of the element more that one time, and to resolve
this problem we can use the dynamic programming to make the laghorithm better.

To make the solution faster we can avoid the recurrent operation with an hash map to store the string "index + sum" as key and store also the
value of the sum.
If the value exist, we can return the value in the hash map. With C++ hash map we have some problem with solution because the hash map is slower,
and a solution is to use a matrix to store the values, we implement the two solution together and we measuring what is the faster solution with
google benchmarks.

### Optimize Space complexity of Matrix

The solutions proposed in the previous section are not enouth to pass all the check inside the online judge, and for this reason in this section
is proposed an additional solution with only a binary vector.
This vector help to memorize the solution that respec the creteria written in the previos section. The solution is stored in the last element of the
binary vector, where the dimension of this array is the total sum of the elment / 2.
