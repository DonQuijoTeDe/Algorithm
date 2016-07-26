#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int Case,M,N;

	cin >> Case;
	while(Case--){
	    cin >> M;

	    vector<int> coins(M,0);
	    for(int i=0;i<M;i++){
	        cin >> coins[i];
	    }

	    cin >> N;
	    vector<long long int> DP(N+1,0);

	    DP[0] = 1;
	    for(int i=0;i<M;i++){
	        for(int j=coins[i];j<=N;j++){
	            DP[j] = DP[j] + DP[j-coins[i]];
	        }
	    }

	    cout << DP[N] << "\n";
	}

	return 0;
}
