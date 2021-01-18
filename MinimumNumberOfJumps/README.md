## [Minimum number of jumps](https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: |
--- | --- | --- |
:heavy_check_mark:  | [Dynamic Programming O(N^2)](https://practice.geeksforgeeks.org/viewSol.php?subId=baf1cefd7c047562a5e759d89a25c39c&pid=701393&user=vpalazzo1) | 1.26 secs |
:heavy_check_mark:  | [Dunamic Programming O(N)](https://practice.geeksforgeeks.org/viewSol.php?subId=2d38f0f16c5b3f11439141e471d15209&pid=701393&user=vpalazzo1)   | 0.24 secs |

## Solution or Solution discussion

### Solution O(N^2)

The solution in `O(N^2)` with dynamic programming consist in to use two additional array, one
called `jumps` and one called `from_pos` with the same dimension of the original array, but with
the only difference in the jumps array that is the init elemes, in other words the elements
are inizialized to `INT32_MIN`.

The solution consist to iterate over the original array and check if the `input[i] > inputs[j] + 1`, if it is true, a set in position `jumps[i] = jums[j] + 1` and in position `from_pos[i] = j`


### Optimized O(N^2) solution

The solution proposed before is not enough to pass all the test for the online judge for this reason the solution proposed to pass all the test is a linear solution, that use two local variable max_reach and steps to memorize the status in this variable and use the inputs array to make the decision.
In this case the solution is to find the maximum elemnt in the input array from the previous max reach and the new that is calculate with the formula i + inputs[i]. During the exectuion we memorize also the number of steps. When this steps are 0 we count one more jump.

The solution has time complexity O(N) and space complexity O(1) because no extra space is needed.
