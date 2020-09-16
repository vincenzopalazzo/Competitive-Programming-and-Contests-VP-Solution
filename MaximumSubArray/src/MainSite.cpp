//
// Created by vincent on 9/16/20.
//

#include <iostream>
#include <vector>
#include "core/MaxSubArrayPos.h"

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, K;
        cin >> N >> K;
        int A[N];
        for(int i=0;i<N;i++) cin>>A[i];
        vector<int> result = max_sub_array_naive_sol(A, N, K);

        for(int i=0; i < result.size(); i++)
            cout << result.at(i) << ' ';

        cout<<'\n';
    }
}
