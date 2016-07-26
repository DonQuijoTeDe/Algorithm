#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	// A DP based C++ program to find minimum
	// number operations to convert str1 to str2
	int Case, m, n, i, j;
	string str1, str2;

	cin >> Case;
	while (Case--){
		cin >> m >> n;
		cin >> str1 >> str2;

		// Create a table to store results of subproblems
		int** DP = new int*[m + 1];
		for (i = 0; i < m + 1; i++){
			DP[i] = new int[n + 1];
			fill(DP[i], DP[i] + n + 1, 0);
		}

		// Initialize
		for (i = 0; i < m + 1; i++){
			DP[i][0] = i;
		}
		for (j = 0; j < n + 1; j++){
			DP[0][j] = j;
		}

		for (i = 1; i < m + 1; i++){
			for (j = 1; j < n + 1; j++){
				if (str1[i - 1] == str2[j - 1]){
					DP[i][j] = DP[i - 1][j - 1];
				}
				else{
					// If the character are different, consider all
					// possibilities and find minimum among:
					// Insert -> DP[i][j-1]
					// Remove -> [i-1][j]
					// Replace -> DP[i-1][j-1]
					DP[i][j] = 1 + min(min(DP[i][j - 1], DP[i - 1][j]), DP[i - 1][j - 1]);
				}
			}
		}

		// Output
		cout << DP[m][n] << "\n";

		for (i = 0; i < m + 1; i++){
			delete[] DP[i];
		}
		delete[] DP;
	}

	return 0;
}
