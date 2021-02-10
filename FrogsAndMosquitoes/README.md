## [Frogs and mosquitoes](https://codeforces.com/contest/609/problem/F)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: |
--- | --- | --- |
:heavy_check_mark:  | [Segment Tree](https://codeforces.com/contest/609/submission/107077987) | 1200 ms |

## Solution or Solution discussion

### Segment Tree solution

To get_position_close_frog this problem is possible use the Segment Tree data structure, without Lazy Propagation for the motivation wrote in the
paper [Segment Tree: A Complete Introduction by Examples](https://gitlab.com/vincenzopalazzo/competitiveprogrammingreport/uploads/b2dcff843e34eedfab80fb737126b465/report.pdf).

The basic idea is to use the Segment Tree to store the data of the frogs, like pos + length tongue, if the frog exist is possible use
a binary search to get the index of this frog, and after that we can make all operation where a frog can eat a mosquito.
However, if there is any frog at the moment that can eat the mosquito, is possible store the mosquito in a multiset (because can be duplicate in position)
and maintain the mosquito that can not eat from any frog in this multiset and check if one of these mosquito can be eaten from a frog with the
new dimension of the tongue.

The Segment tree contains only the position of the frogs sorted by position.

The time complexity of the algorithm is  O((n + m)log(n + m)).
