We define a modified Fibonacci sequence using the following definition:

Given terms t(i) and t(i+1), 1<=i<infinite, term t(i+2) is computed using the following
relation:

t(i+2) = t(i) + (t(i+1))^2

e.g. if term t1=0 and t2=1, term t3=0+1^2=1, term t4=1+1^2=2, term t5=1+2^2=5 etc.

Input Format

A single line of three space-separated integers describing the respective values of t1, t2, and n.

Print a single integer denoting the value of term t(n) in the modified Fibonacci sequence
where the first two terms are t1 and t2.

Sample Input
0 1 5

Sample Output
5
