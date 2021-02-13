## [Two Types of Spells](https://codeforces.com/contest/1398/problem/E?locale=en)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: |
--- | --- | --- |
:heavy_check_mark:  | [Balanced Binary Tree C++ stl](https://codeforces.com/contest/1398/submission/107009206) | TLE ms |
:construction_worker:  | [Balance Binary Tree C++ CPSTL](#TODO) | ?? ms |

## Solution or Solution discussion

The solution used in proposed in the tutorial of the judge and it is reported below

>Let's solve this problem for fixed set of spells. For example, we have a fireball spells with powers f1,f2,…,fm and lighting spells with powers l1,l2,…,lk. We reach the maximum total damage if we can double all k spells with maximum damage. It's possibly iff the set of k largest by power spell (let's denote this set as s) contains at least one fireball spell. Otherwise (if set s contains only lightning spells) the maximum damage reach when we double k−1 largest spells in set s and one largest spell not from set s (if such spell exist).

>Now how do you solve the original problem when spells are added and removed? All we have to do it maintain the set of x largest by power spells (where x is current number of lightning spells), and change this set by adding or removing one spell. Also you have to maintain the sum of spells power in set this set and the number of fireball spells in this set. You can do it by set in C++ or TreeSet on Java.

In this repository is used the same implementation but we want to optimize the style of the code written by the author and at the moment the solution
with C++ STL receive the TLE on the site at test 49, and another solution is under development with the personal Red and Black tree developed in the 
repository [cpstl](https://vincenzopalazzo.github.io/cpstl/).