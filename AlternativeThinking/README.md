## [Alternative Thinking](https://codeforces.com/problemset/problem/603/A)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: | 
--- | --- | --- | 
:heavy_check_mark:  | [Greedy Algorithm](https://codeforces.com/contest/603/submission/104029779) | 31 ms | 

## Solution or Solution discussion

The intuition to resolve this problem is to think about the easy way to flip a substring,
we can imagine the string `1010` the result of this string is the `4`. 
We can reduce the general problem to a sub-problem that consist into fine the continue element in position `i` and in
position `i - 1`, and count how many continues element are inside the string.
In conclusion, we can calculate how many different element are inside the array with the simple subtraction
`size_string - element_equals + 2`, and as result return the minimum element between the size of the string and 
the result of subtraction.

This reduction problem use a greedy algorithm, because start from a general problem that is the 
longest alternating subsequence inside the string to find the continues elements inside the substring.