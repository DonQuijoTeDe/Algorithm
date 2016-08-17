You are a waiter at a party. There are N stacked plates. Each plate has a number
written on it. You start picking up the plates from the top one by one and check
whether the number written on the plate is divisible by P(a prime). The starting
value of P is 2. If the number is divisible, you stack that plate separately with
other P divisible plates. If not, you stack that plate separately with the other
plates that are not divisible by P.

In the next iteration, the value of P changes to the next prime number after P.
You check the plates from the pile that were not divisible by P in the last
iteration. You repeat this process a number of times. By doing this process Q
times, you end up getting different piles of plates. The plates that are not
divisible by the Qth prime (which is our last iteration), from the last pile of
plates. Say you have M (it is clear that M is either Q or Q+1) different piles
of plates. Starting from the first pile, print the number written on the plate
while removing plates from a pile in the same order as described above. Do this
process for all the M piles. Print one value in a single line.

Input Format
The first line contains two space separated integers, N and Q.
The next line contains N space separated integers representing the initial pile
of plates. The leftmost value represents the bottom plate of the pile.

Constraints
1<=N<=5*(10^4)
2<=number(i)<=10^4
1<=Q<=1200

Output Format
Output N lines. Each line contains a number written on the plate. Printing should
be done in the order defined above.

Sample Input
5 2
3 3 4 4 9

Sample Output
4
4
9
3
3
