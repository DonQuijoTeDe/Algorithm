#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N,M,i,j;
    cin >> N >> M;

    long long* DP = new long long[N+1];
    int* coin = new int[M];

    for(i=0;i<M;i++){
        cin >> coin[i];
    }

    fill(DP,DP+N+1,0);
    DP[0] = 1;
    for(i=0;i<M;i++){
        for(j=coin[i];j<=N;j++){
            DP[j] = DP[j] + DP[j-coin[i]];
        }
    }

    cout << DP[N];

    delete[] DP;
    delete[] coin;

    return 0;
}
