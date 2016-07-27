#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Pair{
	int to, w;
	Pair(int first, int second) :to(first), w(second){};
};

int main(){
	int Case, N, M, from, to,
		w, src, cur, nex, i;

	cin >> Case;
	while (Case--){
		cin >> N >> M;

		vector<Pair>* adjList = new vector<Pair>[N + 1];// Use adjList to implement
		bool* inQueue = new bool[N + 1];
		int* Dis = new int[N + 1];
		for (i = 0; i < N + 1; i++){
			Dis[i] = 1e9; // Initialize it to 1e9
			inQueue[i] = false;
			adjList[i].clear();
		}

		for (int i = 0; i < M; i++){
			cin >> from >> to;
			adjList[from].push_back(Pair{ to, 6 });
			adjList[to].push_back(Pair{ from, 6 }); // It is a undirected graph
		}

		cin >> src; // Source
		queue<int> q;
		q.push(src);
		Dis[src] = 0;
		inQueue[src] = true;
		// Shortest Path Faster Algorithm
		while (!q.empty()){
			cur = q.front();
			q.pop();

			inQueue[cur] = false;

			for (int i = 0; i < (int)adjList[cur].size(); i++){
				nex = adjList[cur][i].to; // Next node which is adjacent to current node
				w = adjList[cur][i].w;
				if (Dis[cur] + w < Dis[nex]){
					Dis[nex] = Dis[cur] + w;
					if (!inQueue[nex]){
						q.push(nex);
						inQueue[nex] = true;
					}
				}
			}
		}

		// Output
		for (int i = 1; i <= N; i++){
			if (i == src)
				continue;

			if (Dis[i] == 1e9)
				cout << "-1 ";
			else
				cout << Dis[i] << " ";
		}
		cout << "\n";

		delete[] adjList;
		delete[] inQueue;
		delete[] Dis;
	}

	return 0;
}
