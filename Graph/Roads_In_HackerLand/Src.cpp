#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

struct Edge {
	int from, to, w;
	Edge(int first, int second, int third) :from(first), to(second), w(third) {}
};

struct Pair {
	int to, w;
	Pair(int first, int second) :to(first), w(second) {}
};

int DFS(int, int);
void Kruskal(int, int);
void Init(int, int);
void Union(int,int);
int Find(int);
bool Cmp(Edge, Edge);
void PrintAnswer();

vector<Edge> Edges;
vector<int> Parent;
vector<vector<Pair> > MST;
vector<int> Vis;
vector<long long> Ans;

int N; // number of nodes

//fstream read("input.txt", ios::in);

int main() {
	int M; // number of edges

	cin >> N >> M;

	// As it mentioned, **each of the roads has a distinct length**, so
	// we can use Min Spanning Tree O(ElogE+ElogV) to compute all pairs shortest path
	// instead of using Floyd Warshall O(V^3).(where E, V refers to edge and
	// vertex respectively)
	// Also, we need to deal with the overflow situation of each road's weight.
	// We can simply use the input **Ci** as each roads's weight and do Kruskal
	// algorithm.
	// Then, we can use DFS to compute how many times the roads which were chosen by
	// Kruskal Algorithm are visited.
	// Finally, we use binary computation to transform the times which were
	// stored as decimal into binary representation.

	Edges.clear();
	Parent.clear();
	MST.clear();
	Vis.clear();
	Ans.clear();

	Edges.reserve(M);
	Parent.resize(N + 1);
	Init(N, M);

	sort(Edges.begin(), Edges.end(), Cmp);

	MST.resize(N + 1);
	Kruskal(N, M);

	Vis.resize(N + 1);
	Ans.resize(3 * 1e5);
	DFS(1, -1);

	PrintAnswer();

	return 0;
}

void Init(int N, int M) {
	int i, u, v, w;

	// Store Input Info
	for (i = 0; i < M; i++) {
		cin >> u >> v >> w;
		Edges.push_back({ u,v,w });
	}
	//read.close();

	for (i = 1; i <= N; i++) {
		Parent[i] = i;
	}
}

bool Cmp(Edge a, Edge b) {
	return a.w < b.w;
}

void Kruskal(int V, int E) {
	for (int i = 0, j = 0; i < E, j < V - 1; i++) {
		if (Find(Edges[i].from) == Find(Edges[i].to)) {
			continue;
		}

		// If the edge being added does not cause any cycles,
		// add it to the Min Spanning Tree
		Union(Edges[i].from, Edges[i].to);
		MST[Edges[i].from].push_back({ Edges[i].to, Edges[i].w });
		MST[Edges[i].to].push_back({ Edges[i].from, Edges[i].w });
		j++;
	}
}

int Find(int n) {
	return n == Parent[n] ? n : Parent[n] = Find(Parent[n]);
}

void Union(int a, int b) {
	Parent[Find(a)] = Find(b);
}

int DFS(int cur, int parent) {
	int nex, w, i;
	Vis[cur] = 1;

	// Use DFS to determine how many times each
	// roads is visited and store it into Ans
	for (i = 0; i < MST[cur].size(); i++) {
		nex = MST[cur][i].to;
		w = MST[cur][i].w;
		if (nex == parent) {
			continue;
		}
		Vis[cur] += DFS(nex, cur);
		Ans[w] = (long long)(N - Vis[nex])*Vis[nex];
	}

	return Vis[cur];
}

void PrintAnswer() {
	int digit = 0;

	// Binay computation
	for (int i = 1; i < 3 * 1e5; i++) {
		Ans[i] += Ans[i - 1] / 2;
		Ans[i - 1] %= 2;
		if (Ans[i]) {
			digit = i;
		}
	}

	//fstream write("output.txt", ios::out);

	// Print answer
	for (int i = digit; i >= 0; i--) {
		cout << Ans[i];
	}
	//write.close();
}
