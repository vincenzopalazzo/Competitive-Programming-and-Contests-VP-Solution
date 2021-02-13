## [Next larger element](https://practice.geeksforgeeks.org/problems/next-larger-element/0#)

- Status: Completed :heavy_check_mark: 

Type | Solved  | Benchmark :clock11: | 
--- | --- | --- | 
geeksforgeeks (Stack sol) | :heavy_check_mark: | 0.63 ?? | 
naive | :heavy_check_mark: | 108669830 ns * | 
Based on stack | :heavy_check_mark: | 68048218 ns * | 

- (*) Test benchmark made with inputs size=262144

## Naive Solution

The naive solution use to for loops to iterate over the input array and return the element in position i if the following condition is verified
`inputs.at(i) < inputs.at(j)`. The time complexity is O(N ^ 2) and the space complexity is O(N)

## Stack solution

The solution on stack use a simple trick over the stack characteristic to keep track of non-contiguous decreasing sequences of elements,
when a new element is found all the element < of the actual new element is extracted from the stack and punt inside the result array,
The time complexity of the solution is O(N) and also the space complexity is O(N)