## [VertexCover](https://www.spoj.com/problems/PT07X/)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: |
--- | --- | --- |
:heavy_check_mark:  | [Dynamic Programming](https://www.spoj.com/status/ns=27433283) | 0.06 ms |

## Solution or Solution discussion

The solution to this problem uses the Dynamic Programming and the DFS visit over the Tree.
In addition, the dynamic programming uses the memorization technique where the algorithm memorizes all the node taken.
In addition, if the algorithm chooses the father, it can also take the children, if the algorithm doesn't take the father it
can choose if take the children with the formula `std::min(dp_mem[0][next], dp_mem[1][next])`.

The time and space complexity of the solution is O(V) where V is the number of vertices.
