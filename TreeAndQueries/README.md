## [Tree and Queries](https://codeforces.com/contest/375/problem/D)

- Status: Complete :heavy_check_mark:

Solved | Solution | Time :clock11: |
--- | --- | --- |
:heavy_check_mark:  | [Mo's Algorithm](https://codeforces.com/contest/375/submission/107191868) | 155 ms |

## Solution or Solution discussion

The solution with mo's algorithm require a remapping the tree inside a array where we can run
Mo's algorithm to get the solution at this problem.
The solution is divided in the following steps:

- Remapping Rooted Tree into a simple array with the eulero tour to have the query range from L to R, and the
position L and R is the size of the remapping array from the eulero tour.

- Run the Mo's algorithm and count the number of color with an accumulator vector.

- Return the result that is a vector in my cases that contains the value of the counter for the Kth color.
