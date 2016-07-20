#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int T,N,V,i,j;

	cin >> T;
	while(T--){
	    cin >> V >> N;

	    int* coin = new int[N];
	    int* DP = new int[V+1];
	    fill(DP,DP+V+1,1e9);

	    for(i=0;i<N;i++){
	        cin >> coin[i];
	    }

	    DP[0] = 0;
	    for(i=0;i<N;i++){
	        for(j=coin[i];j<=V;j++){
	            DP[j] = min(DP[j], DP[j-coin[i]]+1);
	        }
	    }

	    if(DP[V] == 1e9){
	        cout << "-1";
	    }
	    else{
	        cout << DP[V];
	    }
	    cout << "\n";

	    delete[] DP;
	    delete[] coin;
	}

	return 0;
}
