/*You are required to complete this function*/
bool is_k_pallin(string s,int k){
	  // This problem is basically a variation of Edit Distance
    string r_s = s;
    reverse(r_s.begin(), r_s.end());
    int m = s.length();

    int DP[101][101];
    memset(DP, 0, sizeof(DP));

    for(int i = 0; i < m + 1; i++){
        DP[i][0] = i;
    }
    for(int j = 0; j < m + 1; j++){
        DP[0][j] = j;
    }

    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < m + 1; j++){
            if(s[i - 1] == r_s[j - 1]){
                DP[i][j] = DP[i - 1][j - 1];
            }
            else{
							  // If the characters are not same, we consider remove operation
								// on the character of first string and the character of second string
					      // Remove -> DP[i-1][j] and DP[i][j-1]
                DP[i][j] = 1 + min(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }
    //cout << DP[m][m] << "\n";

    return DP[m][m] / 2 <= k ? true : false;
}
