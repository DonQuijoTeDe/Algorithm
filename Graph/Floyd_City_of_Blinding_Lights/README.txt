Given a directed, weighted graph, consisting of N nodes and there are edges ,of
specified length between some of them in the graph.

Given Q questions, inquring the shortest distance between a queried pair of nodes
in the graph.

Answer all these questions as quickly as possible !

Input Format
First line has two integers N, denoting the number of nodes in the graph and M,
denoting the number of edges in the graph.
The next M lines each consist of three space separated integers x y r, where x
and y denote the two nodes between which the directed edge (x->y) exists, r
denotes the length of the edge between the corresponding edges.
The next line contains a single integer Q, denoting number of queries.
The next Q lines each, contain two space separated integers a and b, denoting the
node numbers specified according to the question.

Constraints
1<=N<=400
1<=M<=N*(N-1)/2
1<=Q<=10^5
1<=x,y<=N
1<=r<=350

If there are edges between the same pair of nodes with different weights, the last
one (most recent) is to be considered as the only edge between them.

Output Format
Print Q lines, each containing a single integer, specifying the shortest distance
between the nodes specified for that query in the input.

If the distance between a pair of nodes is infinite (not reachable), then print
-1 as the shortest distance.

Sample Input
4 5
1 2 5
1 4 24
2 4 6
3 4 4
3 2 7
3
1 2
3 1
1 4

Sample Output
5
-1
11
