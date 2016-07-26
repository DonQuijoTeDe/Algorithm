#include <vector>
#include <iostream>
using namespace std;

int main() {
    int Case,n,k;
    cin >> Case;
    
    while(Case--){
        // Like Coin Change Problem
        // n -> type of coins

        cin >> n >> k;

        vector<bool> DP(k,false);
        vector<int> Number(n,0);

        for(int i=0;i<n;i++){
            cin >> Number[i];
        }

        DP[0] = true; // Initialize
        for(int i=0;i<n;i++){ // Try all kind of coins
            for(int j=Number[i];j<=k;j++){ // For each kind of coins, try all kind of prices
                DP[j] = DP[j] || DP[j-Number[i]];
            }
        }

        // Output
        for(int i=k-1;k>=0;k--){
            if(DP[k]){
                cout << k << "\n";
                break;
            }
        }

    }

    return 0;
}
