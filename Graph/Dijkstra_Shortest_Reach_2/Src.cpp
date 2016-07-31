#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1000000000

struct Pair {
	int to, w;
	Pair() {};
	Pair(int first, int second) :to(first), w(second) {}
};

int main() {
	// Single Source Shortest Path Problem
	// Use Dijkstra Algorithm or SPFA

	int Case, N, M,
		i, j, u, v, w,
		src, cur, nex;

	cin >> Case;
	while (Case--) {
		cin >> N >> M;

		// Initialize
		vector<Pair>* adjList = new vector<Pair>[N + 1];
		int* Dis = new int[N + 1];
		bool* inQueue = new bool[N + 1];
		for (i = 0; i <= N; i++) {
			adjList[i].clear();
			Dis[i] = INF;
			inQueue[i] = false;
		}

		// Input
		for (i = 0; i < M; i++) {
			cin >> u >> v >> w;
			adjList[u].push_back({ v,w });
			adjList[v].push_back({ u,w });
		}

		cin >> src;
		queue<int> q;
		q.push(src);
		Dis[src] = 0;
		inQueue[src] = true;
		// Shortest Path Faster Algorithm
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			inQueue[cur] = false;

			for (i = 0; i < adjList[cur].size(); i++) {
				nex = adjList[cur][i].to;
				w = adjList[cur][i].w;
				if (Dis[cur] + w < Dis[nex]) {
					Dis[nex] = Dis[cur] + w;
					if (!inQueue[nex]) {
						q.push(nex);
						inQueue[nex] = true;
					}
				}
			}
		}

		// Ourtput
		for (i = 1; i <= N; i++) {
			if (Dis[i] == 0) { // Source
				continue;
			}
			else if (Dis[i] == INF) { // Unreachable
				cout << "-1 ";
			}
			else {
				cout << Dis[i] << " ";
			}
		}
		cout << "\n";

		delete[] adjList;
		delete[] Dis;
		delete[] inQueue;
	}

	return 0;
}
