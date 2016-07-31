John lives in HackerLand, a country with N cities and M bidirectional roads.
Each of the roads has a distinct length, and each length is a power of two (i.e.,
2 raised to some exponent). It's possible for John to reach any city from any
other city.

Given a map of HackerLand, can you help John determine the sum of the minimum
distances between each pair of cities? Print your answer in **binary representation.**

Input Format
The first line contains two space-seperated integers denoting N (the number of
cities) and M (the number of roads), respectively.
Each line i of the M subsequent lines contains the respective values of Ai, Bi,
and Ci as three space-separated integers. These values define a **bidirectional**
road between cities Ai and Bi having length 2^(Ci).

Constraints
1<=N<=10^5
1<=M<=2*10^5
1<=Ai,Bi<=N, Ai!=Bi
0<=Ci<M
If i!=j, then Ci!=Cj

Output Format
Find the sum of minimum distances of each pair of cities and print the answer
in binary representation.

Sample Input
5 6
1 3 5
4 5 0
2 1 3
3 2 1
4 3 4
4 2 2

Sample Output
1000100
