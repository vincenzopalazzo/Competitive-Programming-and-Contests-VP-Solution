## [Triplets](https://github.com/rossanoventurini/CompetitiveProgramming/blob/master/Exams/Text14022018.pdf)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: | 
--- | --- | --- | 
:construction:  | [Naive 3 for look](#TODO) | XXXX ms | 
:construction:  | [Segment Tree](#TODO) | XXXX ms | 
:construction:  | [Single Fenwick Tree](#TODO) | XXXX ms | 
:heavy_check_mark:  | [Double Fenwick Tree](#TODO) | XXXX ms | 

## Solution or Solution discussion

We now that the size of the segment is N and all items are inside the range [0 - N], so wit this assertion 
we can use to start the remapping of the element with a Fenwick Tree.

# Solution in time O(n^2) and space O(n)

I use the fenwick tree to make a preprocessing, in fact with the fenwick tree we mantains the tracking of the 
each value, to do this operation we perform the operation on Fenwick tree `fenwick_tree.update(inputs[i], 1)`
this action is implemented inside the help method precompute.

After the precompute operation we need to make a double for loop and check when we are able to find the element 
`input[i] < input[j]` when we are able to find it we can make the sum inside the fenwick tree that look like
`count += (fenwick_tree.sum(inputs.size()) - fenwick_tree.sum(inputs[j]));`.
You can see this solution implemented inside the procedure call `count_triplets_precomputing_bit`.

# Solution in time O(n log n) and space O(n) ?? TRUE?

This solution use two Fenwick tree to maintain the prefix and the suffix (smaller element and greater element), where
the fenwick tree that contains the greater element was precompute with the procedure described in the solution with 
time O(n ^ 2),

The counting operation was performed with the following logic

```c++
    for (std::size_t i = 0; i < inputs.size(); i++) {
        auto smallest_elements = fenwick_smallest.sum(inputs[i] - 1);
        auto greatest_elements = fenwick_greater.sum(inputs.size()) - fenwick_greater.sum(inputs[i]);
        count += (smallest_elements * greatest_elements);
        fenwick_smallest.update(inputs[i], 1);
        fenwick_greater.update(inputs[i], -1);
    }
```