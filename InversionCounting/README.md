## [Inversion Counting Problem](https://www.spoj.com/problems/INVCNT/) or [Another reference](https://www.hackerrank.com/challenges/ctci-merge-sort/submissions/code/187167773)

- Status: Completed :heavy_check_mark:
                   
Algorithm | Solved | Solution | Time :clock11: | 
--- | --- | --- | --- | 
[Merge Sort](https://github.com/vincenzopalazzo/cpstl/tree/master/cpp) |:heavy_check_mark: | [Sol](https://www.spoj.com/status/ns=26885206) | 0.15
[Fenwick Tree](https://github.com/vincenzopalazzo/cpstl/tree/master/cpp) | :construction: | [Sol](#) | ?

## Solution description

The complete solution use the merge sort to count the number of inversion count, the basic idea the merge sort
use the invention technique to sort the array, and in this solution, we count the number of inversions that the merge sort
need to sort the array.

The time complexity is O(N log N) and the space complexity is O(N log N) because we need to use the tree to make the remapping of the input.