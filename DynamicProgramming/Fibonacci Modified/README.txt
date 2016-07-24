We define a modified Fibonacci sequence using the following definition:

Given terms t(i) and t(i+1), 1<=i<infinite, term t(i+2) is computed using the
following relation:

t(i+2) = t(i) + (t(i+1))^2

e.g. if term t1=0 and t2=1, term t3=0+1^2=1, term t4=1+1^2=2, term t5=1+2^2=5 etc.

Input Format

A single line of three space-separated integers describing the respective values
of t1, t2, and n.

Print a single integer denoting the value of term t(n) in the modified Fibonacci
sequence where the first two terms are t1 and t2.

Sample Input
0 1 5

Sample Output
5
--------------------------------------------------------------------------------
Since the max digits of this problem would up to 10^6
The original code I wrote ran in C++ would cause TLE(I use
string operations and the "insert" method would slow
down my execution time, one insertion for O(N) where N
is the length of the string and about 360s to print out
the maximum value)

But I think if you still want to use C++ to deal with
this big integer problem, maybe you can try using "array"
i.e. if the string is "12345" then store array[0] as 1,
array[1] as 2 etc. Or you can store array[0] as 1234 then
array[1] as 5
