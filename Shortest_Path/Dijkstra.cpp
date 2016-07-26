#include <iostream>
#include <queue>
#define INT_MAX 1000
using namespace std;

struct Node {
    int b,d;
};

bool operator<(const Node& n1, const Node& n2) {
    return n1.d > n2.d;
}

static int w[9][9];
static int d[9];
static int parent[9];
static bool visit[9];


void dijkstra(int source) {
    for(int i=0;i<9;i++) {
        visit[i]=false;
        d[i]= INT_MAX;
    }

    priority_queue<Node> PQ;

    d[source]=0;
    parent[source]=source;
    PQ.push((Node){source, d[source]});

    for(int i=0;i<9;i++) {
        int a=-1;
        while(!PQ.empty() && visit[a=PQ.top().b]) {
            PQ.pop();
            if(a==-1) break;
            visit[a]=true;
            for(int b=0;b<9;b++) {
                if(!visit[b] && d[a]+w[a][b] < d[b]) {
                    d[b] = d[a]+w[a][b];
                    parent[b] = a;
                    PQ.push((Node){b, d[b]});
                }
            }
        }
    }
}

int main() {

    return 0;
}
