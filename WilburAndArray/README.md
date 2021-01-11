## [Wilbur and Array](https://codeforces.com/problemset/problem/596/B)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: | 
--- | --- | --- | 
:heavy_check_mark:  | [Greedy algorithm](https://codeforces.com/contest/596/submission/104033377) | 156 ms | 

## Solution or Solution discussion

The general solution to find the number of step to make the array *A* equal to input array was reduced to a local
problem to find and sum the difference from element in position `steps += inputs[i] - inputs[i-1]`.
This solution use the greedy algorithm