#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> DP(n, 0);
    vector<int> Rate(n, 0);
    cin >> Rate[0];
    DP[0] = 1;

    // Time Complexity: O(n*n), TLE
    /*for(int i = 1; i < n; i++){
        cin >> Rate[i];

        if(Rate[i] > Rate[i - 1])
            DP[i] = DP[i - 1] + 1;

        else if(DP[i - 1] == 1){
            DP[i] = 1;
            for(int j = i - 1; j >= 0; j--){
                if(Rate[j] > Rate[j + 1])
                    DP[j] = max(DP[j + 1] + 1, DP[j]);
                else
                    break;
            }
        }
        else
            DP[i] = 1;
    }*/

    // Time Complexity: O(n)
    for(int i = 1; i < n; i++){
        cin >> Rate[i];
        if(Rate[i] > Rate[i - 1])
            DP[i] = DP[i - 1] + 1;
        else
            DP[i] = 1;
    }
    for(int i = n - 1; i >= 0; i--){
        if(Rate[i] > Rate[i + 1])
            DP[i] = max(DP[i + 1] + 1, DP[i]);
    }

    long long int result = 0;
    for(int i = 0; i < n; i++)
        result += DP[i];

    cout << result;

    return 0;
}
/*
Input:
5
2
1
1
4
3

Output:
7
*/
