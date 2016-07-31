#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool Searching(int);

vector<int> DP;

int main() {
	int Case, N, temp;

	cin >> Case;
	while (Case--) {
		// We can use DP to speed up
		// Time Complexity: O(N)
		cin >> N;

		DP.clear();
		DP.resize(N + 2);

		DP[0] = 0;
		for (int i = 1; i <= N; i++) {
			cin >> temp;
			DP[i] = DP[i - 1] + temp;
		}
		DP[N + 1] = DP[N];

		Searching(N) ? cout << "YES\n" : cout << "NO\n";

	}

	return 0;
}

bool Searching(int N) {
	for (int i = 1; i <= N; i++) {
		if (DP[i - 1] == DP[N + 1] - DP[i]) {
			return true;
		}
	}

	return false;
}
