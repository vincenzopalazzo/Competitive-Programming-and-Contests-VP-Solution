# MKTHNUM Benchmarks

To solve the problem MKTHNUM by [Spoj](https://www.spoj.com/) are proposed two different solutions that use two different types of Segment Tree, one solution uses the Segment Tree with Persistence technique, and the second solution use a custom implementation of the Segment Tree, wherein each node is stored a Balanced Binary Tree with the element in the range $[L, R]$.

## Problem

Given an array of $N$ of different integer numbers, the algorithm needs to answer a sequence of queries
with the following format $Q(L, R, K)$ where $L$ and $R$ is the range $[L, R]$ where the algorithm needs to return the $Kth$ element in the range.


In particular, the query needs to be able to answer a question like "What would be the kth number in a range $[i, j]$, if this the element of this
subarray was sorted?"

#### Example 

Consider an array like the array A = {1, 5, 2, 6, 3, 7, 4}. Where and query can ask to find the *3rd* number in the sorted segment from _[2, 5].

After sorting the elements in the range _[2, 5]_, we get the segment composed from the following element {2, 3, 5, 6} and the third number in the range is 5, and therefore the correct answer to the query is 5.

## Solution with a custom implementation of Segment Tree.

The basic idea to solve this problem is to store a Balanced Binary Tree in each node of the segment, the balanced binary tree help to maintain the element stored inside the segments.
An implementation is available on the GitHub repository [Competitive-Programming-and-Contests-VP-Solution](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/).
However, the time complexity is not enough to solve the problem with the online Judge, and the C++ solution that gets a Time Limit Exceeded available at the following [link](https://www.spoj.com/status/MKTHNUM,macros1/).

To solve with success the problem with online Judge we need to use Persistent Tree, and the solution is described in the next section.

## Solution with Persistent Segment Tree

Before introducing the solution, we need to introduce a limitation in the previous solution, that is on the Sorting element, in this problem, there isn't a present update query and this meant that the input array will not change during the execution of the algorithm. With this observation, we can say that is possible to sort the array before build the segment tree and it can help to improve the solution time of the previous solution.

The solution with Persistent Segment Tree uses this observation to make a simple remapping of them and build an incremental Persistent Segment Tree, and as the last step of the algorithm, we perform all the query of the problem on the Segment Tree, in the range of $[L, R]$ were in the case of Persistent Segment Tree is to perform a query in two instances of the Segment Tree, on is the instance in position L and the last one is the instance in position R. After that the algorithm performs a binary search to find the kth element in the range. The code solution is available on [Competitive-Programming-and-Contests-VP-Solution](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/).

This solution is faster than the solution in the previous section because the time complexity is $\mathcal{O}(Q \log N)$ where the Q is the number of query and N is the size of the array, but on the other hand, the space complexity is more complex to calculate because the Persistent Segment Tree contains also a vector with the history of the data struct where the head element in these data structure can contain \log N new element. 

## Benchmark Discussion

To compare the solution two solutions proposed in the previous section is used a micro benchmarks library as Google Benchmark to compare the two solutions during the execution of it. This section contains a complete discussion of the results.


```python
from core_chart import ( make_segment_tree_and_persistent_segmet_tree_benchmark_chart, 
make_segment_tree_and_persistent_segmet_tree_benchmark_table )

make_segment_tree_and_persistent_segmet_tree_benchmark_chart()
```


    
![png](output_2_0.png)
    


How it shows in the Figure the Persistent Segment Tree is slower than the custom Segment Tree when the query number are few, but when the query number increases number the Persistent Segment Tree maintains the $\log N$ time complexity and makes the solution to the problem faster. In addition, the persistent Segment Tree can be faster because the implementation of it uses the C++ STD container to make and use the pointer. How one of the Guidelines of C++ is to avoid making the pointer directly. This is not a good choice when are solving a Competitive Programming problem because the velocity of the algorithm is more important than the implementation, but this is an implementation choice, and this help to understand that also with a not faster implementation the Persistent Segment Tree help to resolve the problem in an efficient way.

The results show in the Figure above, are summarized in the table below.


```python
make_segment_tree_and_persistent_segmet_tree_benchmark_table()
```


<div>
<style scoped>
    .dataframe tbody tr th:only-of-type {
        vertical-align: middle;
    }

    .dataframe tbody tr th {
        vertical-align: top;
    }

    .dataframe thead th {
        text-align: right;
    }
</style>
<table border="1" class="dataframe">
  <thead>
    <tr style="text-align: right;">
      <th></th>
      <th>Persistent Segment Tree</th>
      <th>Custom Segment Tree</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th>Q: 4</th>
      <td>57642648688.000916 ns</td>
      <td>38966243126.99896 ns</td>
    </tr>
    <tr>
      <th>Q: 8</th>
      <td>55842193433.99309 ns</td>
      <td>38115228559.99828 ns</td>
    </tr>
    <tr>
      <th>Q: 16</th>
      <td>61573267574.00005 ns</td>
      <td>42337273312.99997 ns</td>
    </tr>
    <tr>
      <th>Q: 32</th>
      <td>62660775567.004745 ns</td>
      <td>84876541783.0 ns</td>
    </tr>
    <tr>
      <th>Q: 64</th>
      <td>57592852565.00152 ns</td>
      <td>125670119671.00006 ns</td>
    </tr>
    <tr>
      <th>Q: 128</th>
      <td>51162499106.00163 ns</td>
      <td>193710662405.00113 ns</td>
    </tr>
    <tr>
      <th>Q: 256</th>
      <td>53811262555.00567 ns</td>
      <td>377359894010.99866 ns</td>
    </tr>
    <tr>
      <th>Q: 512</th>
      <td>53680732222.00474 ns</td>
      <td>580985333179.9987 ns</td>
    </tr>
    <tr>
      <th>Q: 1024</th>
      <td>49803293349.99988 ns</td>
      <td>1225670039757.0002 ns</td>
    </tr>
    <tr>
      <th>Q: 2048</th>
      <td>46770501815.0009 ns</td>
      <td>2639171862127.9995 ns</td>
    </tr>
    <tr>
      <th>Q: 4096</th>
      <td>46391210179.99423 ns</td>
      <td>5254978207839.0 ns</td>
    </tr>
    <tr>
      <th>Q: 8192</th>
      <td>46273517681.001976 ns</td>
      <td>10700194038434.002 ns</td>
    </tr>
    <tr>
      <th>Q: 16384</th>
      <td>45852934573.9953 ns</td>
      <td>21003378790614.0 ns</td>
    </tr>
  </tbody>
</table>
</div>


### Addition information about the Benchmarks

The array dimension equal to $2^{21}$ and the the query are increasing choose in a range from $2^{2}$ to $2^{14}$.

All the code of the benchmarks are available on [Competitive-Programming-and-Contests-VP-Solution](https://vincenzopalazzo.github.io/Competitive-Programming-and-Contests-VP-Solution/).
