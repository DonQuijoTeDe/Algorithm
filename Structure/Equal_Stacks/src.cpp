#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n1, n2, n3, i, j, index, value = 1e9;
	bool check;

	vector<int> N(3);
	vector<int> H[3];
	vector<int> DP[3];

	for (i = 0; i < 3; i++) {
		cin >> N[i];
	}

	for (i = 0; i < 3; i++) {
		if (N[i] < value) {
			value = N[i];
			index = i;
		}

		H[i].resize(N[i]);
		for (j = 0; j < N[i]; j++) {
			cin >> H[i][j];
		}

		reverse(H[i].begin(), H[i].end()); // reverse the array

		DP[i].clear();
		DP[i].resize(N[i]);
		DP[i][0] = H[i][0];
		for (j = 1; j < N[i]; j++) {
			DP[i][j] = DP[i][j - 1] + H[i][j]; // compute the sum
		}
	}

	check = false;
	vector<int>::iterator it;
	for (i = N[index] - 1; i >= 0; i--) {
		for (j = 0; j < 3; j++) {
			if (j == index)
				continue;

			it = find(DP[j].begin(), DP[j].end(), DP[index][i]);
			if (it == DP[j].end()) {
				check = false;
				break;
			}

			check = true;
		}

		if (check) {
			cout << DP[index][i];
			break;
		}
	}

	if (!check)
		cout << "0";

	return 0;
}
