You have three stacks of cylinders where each cylinder has the same diameter,
but they may vary in height. You can change the height of a stack by removing
and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are
exactly the same height. This means you must remove zero or more cylinders from
the top of zero or more of the three stacks until they're all the same height,
then print the height. The removals must be performed in such a way as to maximize
the height.

Note: An empty stack is still a stack.

Input Format
The first line contains three space-separated integers, n1, n2, and n3, describing
the respective number of cylinders in stacks 1, 2, and 3. The subsequent lines
describe the respective heights of each cylinder in a stack from top to bottom:

The second line contains n1 space-separated integers describing the cylinder
heights in stack 1.
The third line contains n2 space-separated integers describing the cylinder
heights in stack 2.
The fourth line contains n3 space-separated integers describing the cylinder
heights in stack 3.

Constraints
0<n1,n2,n3<=10^5
0<height of any cylinder<=100

Output Format
Print a single integer denoting the maximum height at which all stacks will be
of equal height.

Sample Input
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1

Sample Output
5
