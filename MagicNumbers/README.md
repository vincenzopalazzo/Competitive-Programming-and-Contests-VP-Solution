## [Magic Numbers](https://codeforces.com/problemset/problem/320/A?locale=en)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: | 
--- | --- | --- | 
:heavy_check_mark:  | [Greedy Algorithm](https://codeforces.com/contest/320/submission/104035369) | 62 ms | 

## Solution or Solution discussion

To find if the number is a magic number we can work in a string an make some check to define when the number is not a
magic number, in other words a magic number is defined from the concatenation of tree different type of number 
that are

- '1', '14', '144'

A number it is not a magic number when

- There is a number different from 1 and 4 inside the number
- If the first point is true, another check is that the string should not start with '4'
- and at the end we need to find inside the substring if the number contains the substring '444'

If the previous point are all verified the number is a magic number.