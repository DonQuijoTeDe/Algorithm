#include<iostream>
using namespace std;
int main(){
	int T, n, amount, i, j;

	cin >> T;
	while(T--){
	    cin >> n >> amount;

	    int* DP = new int[amount+1];
	    int* coin = new int[n];

	    for(i=0;i<n;i++){
	        cin >> coin[i];
	    }

	    fill(DP,DP+amount+1,1e9);
	    DP[0] = 0;
	    for(i=0;i<n;i++){ // Try all kinds of coins
	        for(j=coin[i];j<=amount;j++){ // Try all kinds of money
	            DP[j] = min(DP[j], DP[j-coin[i]]+1);
	        }
	    }

	    // Output
	    if(DP[amount] == 1e9){
	        cout << "-1";
	    }
	    else{
	        cout << DP[amount];
	    }
	    cout << "\n";

	    delete[] DP;
	    delete[] coin;
	}

	return 0;
}
