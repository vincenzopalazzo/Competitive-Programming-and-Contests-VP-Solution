## [Leaders in array](https://www.geeksforgeeks.org/leaders-in-an-array/)

- Status: Completed :heavy_check_mark:

Solved | Solution | Time :clock11: | 
--- | --- | --- | 
:heavy_check_mark:  | [Queue](https://practice.geeksforgeeks.org/viewSol.php?subId=f6a9be9555ac4dee759034fadbe4e7e8&pid=701210&user=vpalazzo1) | 0.55 ms | 

## Solution or Solution discussion

The solution use a Double ended queues and each new element >= is put in front of the data stucture.

In addition the solution for the 2020 in not longer available because the site was update in December 2020,
the solution for the new site is

```cpp
vector<int> leaders(int a[], int n){
    deque<int> result;
    int max_right_value = a[n - 1];
    max_right_value = max_right_value;
    result.push_front(max_right_value);
    for (int i = n - 2; i >= 0; i--) {
        int actual_val = a[i];
        if (actual_val >= max_right_value) {
            max_right_value = actual_val;
            result.push_front(max_right_value);
        }
    }
    std::vector<int> tmp;
    tmp.reserve(n);
    for (auto elem : result) {
        tmp.push_back(elem);
    }
    return tmp;
}
```
