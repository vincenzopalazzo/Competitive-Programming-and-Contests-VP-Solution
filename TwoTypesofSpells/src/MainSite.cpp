#include <bits/stdc++.h>

using namespace std;

int n;
set <int> sDouble;
long long sum[2];
set <int> s[2];
int cntDouble[2];

// 0: 0 -> 1
// 1: 1 -> 0
void upd(int id) {
    assert(s[id].size() > 0);
    int x = *s[id].rbegin();
    if (id == 1) x = *s[id].begin();
    bool d = sDouble.count(x);

    sum[id] -= x, sum[!id] += x;
    s[id].erase(x), s[!id].insert(x);
    cntDouble[id] -= d, cntDouble[!id] += d;
}


int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tp, x;
        cin >> tp >> x;// tp = 1 if double

        if (x > 0) {
            sum[0] += x;
            s[0].insert(x);
            cntDouble[0] += tp;
            if (tp) sDouble.insert(x);
        } else {
            x = -x;
            int id = 0;
            if (s[1].count(x)) id = 1;
            else assert(s[0].count(x));

            sum[id] -= x;
            s[id].erase(x);
            cntDouble[id] -= tp;
            if (tp) {
                assert(sDouble.count(x));
                sDouble.erase(x);
            }
        }

        int sumDouble = cntDouble[0] + cntDouble[1];
        while (s[1].size() < sumDouble) upd(0);
        while (s[1].size() > sumDouble) upd(1);
        while (s[1].size() > 0 && s[0].size() > 0 && *s[0].rbegin() > *s[1].begin()) {
            upd(0);
            upd(1);
        }
        assert(s[1].size() == sumDouble);

        long long res = sum[0] + sum[1] * 2;
        if (cntDouble[1] == sumDouble && sumDouble > 0) {
            res -= *s[1].begin();
            if (s[0].size() > 0) res += *s[0].rbegin();
        }
        cout << res << endl;
    }
    return 0;
}