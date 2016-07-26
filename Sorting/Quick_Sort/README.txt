Print Sub-Arrays
In this challenge, print your array every time your partitioning method finishes,
i.e. whenever two subarrays, along with the pivot, is merged together.

1. The first element in a sub-array should be used as a pivot.
2. Partition the left side before partitioning the right side.
3. The pivot should be placed between sub-arrays while merging them.
4. Array of length 1 or less will be considered sorted, and there is no need to sort
   or to print them.

Note
Please maintain the original order of the elements in the left and right partitions
while partitioning around a pivot element.

For example: Partition about the first element for the array A[]={5, 8, 1, 3, 7,
             9, 2} will be {1, 3, 2, 5, 8, 7, 9}

Input Format
There will be two lines of input:

n - the size of the array
ar - the n numbers of the array

Output Format
Print every partitioned sub-array on a new line.

Constraints
1<=n<=1000
-1000<=x<=1000, x belongs to ar
Each number is unique.

Sample Input
7
5 8 1 3 7 9 2

Sample Output
2 3
1 2 3
7 8 9
1 2 3 5 7 8 9
