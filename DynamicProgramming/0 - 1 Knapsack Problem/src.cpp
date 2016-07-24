#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
  int val,wt;
};

int main() {
	int T, W, N, i, j;

    cin >> T;
	while (T--) {
		cin >> N >> W;

		Item* item = new Item[N];
		int** DP = new int*[N + 1];

		for (i = 0; i < N; i++) {
			cin >> item[i].val;
		}

        for (i = 0; i < N; i++) {
			cin >> item[i].wt;
		}

		for (i = 0; i <= N; i++) {
			DP[i] = new int[W + 1];
			fill(DP[i], DP[i] + W + 1, 0);
		}

		for (i = 0; i < N; i++) { // Try every kind of track
			for (j = 0; j <= W; j++) { // Try every kind of weight
				if (j - item[i].wt < 0) {
					DP[i + 1][j] = DP[i][j];
					//cout << "DP[" << i + 1 << "][" << j << "] = " << DP[i][j] << "\n";
				} else {
					DP[i + 1][j] = max(DP[i][j], DP[i][j - item[i].wt] + item[i].val);
					/*cout << "DP[" << i + 1 << "][" << j << "] = max { "
						<< "DP[" << i << "][" << j << "]:" << DP[i][j]
						<< ", DP[" << i << "][" << j - Tracks[i] << "]:"
						<< DP[i][j - Tracks[i]] << " + " << "Tracks[" << i << "]:" << Tracks[i] << " }\n";*/
				}
			}
		}

        cout << DP[N][W] << "\n";

		for (i = 0; i <= N; i++)
			delete[] DP[i];
		delete[] DP;
		delete[] item;

	}

	return 0;
}
