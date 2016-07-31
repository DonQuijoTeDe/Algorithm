#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define INF 1e9

struct Pair {
	int to, w;
	Pair(int first, int second) :to(first), w(second) {}
	bool operator< (const Pair& n) const // Needed by Priority-Queue
	{
		return n.w < w;
	}
};

void Init(int, int);
int Prim(int, int);

vector<vector<Pair> > adjList;
vector<int> Parent;
vector<int> Key;
vector<bool> inMST;

int main() {
	// Min Spanning Tree Problem
	// Use Prim's Algorithm(implemented in std::priority_queue)

	int N, M, src;

	cin >> N >> M;
	Init(N, M);

	cin >> src;
	cout << Prim(src, N);

	return 0;
}

void Init(int N, int M) {
	int u, v, w, i;

	adjList.clear();
	Parent.clear();
	Key.clear();
	inMST.clear();

	adjList.resize(N + 1);
	Parent.resize(N + 1);
	Key.resize(N + 1);
	inMST.resize(N + 1);

	for (i = 0; i < M; i++) {
		cin >> u >> v >> w;
		adjList[u].push_back({ v, w });
		adjList[v].push_back({ u, w }); // For undirected graph
	}

	for (i = 1; i <= N; i++) {
		Parent[i] = -1;
		Key[i] = (int)INF;
		inMST[i] = false;
	}
}

int Prim(int src, int N) {
	int cur, nex, i, w, answer = 0;
	priority_queue<Pair> pq;
	pq.push(Pair{ src,0 });
	Key[src] = 0;

	while (!pq.empty()) {
		cur = pq.top().to;
		if (inMST[cur]) {
			pq.pop();
			continue;
		}

		answer += pq.top().w;
		inMST[cur] = true;
		pq.pop();

		for (i = 0; i < (int)adjList[cur].size(); i++) {
			nex = adjList[cur][i].to;
			w = adjList[cur][i].w;
			if (!inMST[nex] && w < Key[nex]) { // Like union-find operations in Kruskal's algorithm
				Key[nex] = w;
				pq.push(Pair{ nex,Key[nex] });
				Parent[nex] = cur;
			}
		}
	}

	/*for (int i = 1; i < N; i++) {
		cout << Parent[i] << "---" << i << "\n";
	}*/

	return answer;
}
