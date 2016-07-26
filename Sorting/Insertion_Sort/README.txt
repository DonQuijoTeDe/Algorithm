Input Format
There will be two lines of input:

s - the size of the array
ar - a list of numbers that makes up the array

Output Format
On each line, output the entire array at every iteration.

Constraints
1<=s<=1000
-10000<=x<=10000, x belongs to ar

Sample Input
6
1 4 3 5 6 2

Sample Output
1 4 3 5 6 2
1 3 4 5 6 2
1 3 4 5 6 2
1 3 4 5 6 2
1 2 3 4 5 6

Explanation
Insertion Sort checks 4 first and doesn't need to move it, so it just prints out
the array. Next, 3 is inserted next to 1, and the array is printed out. This continues
one element at a time until the entire array is sorted.
