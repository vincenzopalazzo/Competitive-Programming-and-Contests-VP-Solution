## [TrappingRainWater problem](https://practice.geeksforgeeks.org/problems/trapping-rain-water/0)

- Status: Complete :heavy_check_mark:


Solved | Solution | Time :clock11: | 
--- | --- | --- | 
:heavy_check_mark:  | [Two Pointer solutions](https://practice.geeksforgeeks.org/viewSol.php?subId=cc50c97ecabf63294da3a36ab6b5722f&pid=701211&user=vpalazzo1) | TLE |
:heavy_check_mark:  | [Opt. Two Pointer solutions](https://practice.geeksforgeeks.org/viewSol.php?subId=ad0b618f60255891854c6d4d7df94219&pid=701211&user=vpalazzo1) | ? ms | 

## Solution or Solution discussion

To solve the problem of Trapping Rain Water, the technique two pointers is used, and the basic idea is to maintain the value to the left of one point and to the right of the same point. In the end, the result is the minimum value between the pointers.
The time complexity of this solution is O(N ^ 2) and the space complexity is O (1).

It is possible to use the optimization to maintain, and make the time complexity of the solution equal to O(N) but the space complexity will increase
to O(N) because the solution uses to array to store the value to the right side of the value in position i, and to the left of the value i.
The resul in position i, is calculate with the formula `std::min(left[i], right[i]) - input[i]` 