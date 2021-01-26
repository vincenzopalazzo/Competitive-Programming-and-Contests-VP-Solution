## [N meetings in one room ](https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: |
--- | --- | --- |
:heavy_check_mark:  | [Greedy](https://practice.geeksforgeeks.org/viewSol.php?subId=ba7290a98c43f7a39fd3ea2d4406e446&pid=701364&user=vpalazzo1) | 0.55 s |

## Solution or Solution discussion

### Gready Solution

The solution to solve this problem use the greedy approach and the algorithm sorts inputs arrays by ending time and
check if the next meeting has a good start time (start[i] > end[i - 1]), if yes the meeting in position i can be choose.

The complexity time of this algorithm is O(N log  N) and the space complexity is O(1) no additional space is needed.
