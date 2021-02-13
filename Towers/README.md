## [Towers](https://codeforces.com/contest/37/submission/93820525)

- Status: Completed :heavy_check_mark: 

Type | Solved  | Benchmark :clock11: | 
--- | --- | --- | 
:heavy_check_mark: | [Binary Search](https://codeforces.com/contest/37/submission/107281637)| 62 ms | 

## Binary Search Solution

The solution works on a sorted input array and uses the binary search to search the element i in the range on array `[i + 1, inputs.size() - 1]`
if the element doesn't exist we maintain a counter of the element maximum in the range, otherwise, we found a tower.

The time complexity of the solution is O(N log N) and the space complexity is O(1).