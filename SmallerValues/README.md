## [Smaller values](file:///home/vincent/Downloads/Text14012019.pdf)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: |
--- | --- | --- |
:construction:  | [Mo Algorithm](#TODO) | XXXX ms |
:heavy_check_mark:  | [Segment Tree](#TODO) | ? ms |
:heavy_check_mark:  | [Fenwick Tree](#TODO) | ? ms |

## Solution or Solution discussion

The basic idea is to make a smart idea to get the range and after that we need to count how many value are smaller than
the query value.
With the Segment Tree, we can store the range inside each node, and with the fenwick tree is possible make a fenwick tree
with all 0 and make an range update from `end  - start`.

Time complexity of the solution is complexity: O((m + n) log n) and the space complexity: O(n))
