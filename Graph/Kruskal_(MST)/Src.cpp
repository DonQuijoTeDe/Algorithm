#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int from, to, w;
	Edge(int first, int second, int third) :from(first), to(second), w(third) {}
};

int Kruskal(int, int);
void Init(int, int);
void Union(int,int);
int Find(int);
bool Cmp(Edge, Edge);

vector<Edge> Edges;
vector<int> Parent;

int main() {
	// Min Spanning Tree Problem
	// As it mentioned, the Cmp function being used by sorting
	// need to be redesigned
	int N, M;
	cin >> N >> M;

	Edges.clear();
	Parent.clear();

	Edges.reserve(M);
	Parent.resize(N + 1);
	Init(N, M);

	stable_sort(Edges.begin(), Edges.end(), Cmp);

	cout << Kruskal(N, M);

	return 0;
}

void Init(int N, int M) {
	int i, u, v, w, src;

	// Store Input Info
	for (i = 0; i < M; i++) {
		cin >> u >> v >> w;
		Edges.push_back({ u,v,w });
	}
	cin >> src; // Ignore

	for (i = 1; i <= N; i++) {
		Parent[i] = i;
	}
}

bool Cmp(Edge a, Edge b) {
	if (a.w == b.w) {
		return a.from + a.to + a.w < b.from + b.to + b.w;
	}
	else {
		return a.w < b.w;
	}
}

int Kruskal(int V, int E) {
	int answer = 0;
	for (int i = 0, j = 0; i < E, j < V - 1; i++) {
		if (Find(Edges[i].from) == Find(Edges[i].to)) {
			continue;
		}
		Union(Edges[i].from, Edges[i].to);
		answer += Edges[i].w;
		j++;
	}

	return answer;
}

int Find(int n) {
	return n == Parent[n] ? n : Parent[n] = Find(Parent[n]);
}

void Union(int a, int b) {
	Parent[Find(a)] = Find(b);
}
