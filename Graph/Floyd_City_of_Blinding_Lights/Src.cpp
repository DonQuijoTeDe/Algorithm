#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000000

int main() {
	// All Pairs Shortest Path Problem
	// Use Floyd Warshall Algorithm
	int N, M, x, y, w, query,
		i, j, k,
		src, des;

	cin >> N >> M;

	int** Dis = new int*[N + 1];
	for (i = 0; i <= N; i++) {
		Dis[i] = new int[N + 1];
		fill(Dis[i], Dis[i] + N + 1, INF);
		Dis[i][i] = 0;
	}

	// Input
	for (i = 0; i < M; i++) {
		cin >> x >> y >> w;
		Dis[x][y] = w;
	}

	// Floyd Warshall Algorithm
	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				if (Dis[i][k] + Dis[k][j] < Dis[i][j]) {
					Dis[i][j] = Dis[i][k] + Dis[k][j];
				}
			}
		}
	}

	// Output
	cin >> query;
	for (i = 0; i < query; i++) {
		cin >> src >> des;
		if (Dis[src][des] == INF)
			cout << "-1\n";
		else
			cout << Dis[src][des] << "\n";
	}

	for (i = 0; i <= N; i++) {
		delete[] Dis[i];
	}
	delete[] Dis;

	return 0;
}
