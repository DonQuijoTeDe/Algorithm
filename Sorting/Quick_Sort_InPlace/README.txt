Challenge
Create an in-place version of Quicksort. You need to follow Lomuto Partitioning
method.

Guideline
Instead of copying the array into multiple sub-arrays, use indices to keep track
of the different sub-arrays. You can pass the indices to a modified partition method.
The partition method should partition the sub-array and then return the index
location where the pivot gets placed, so you can then call partition on each side
of the pivot.

1. Always select the last element in the 'sub-array' as a pivot.
2. Partition the left side and then the right side of the sub-array.
3. Print out the whole array at the end of every partitioning method.
4. An array of length  or less will be considered sorted, and there is no need
   to sort or to print them.
Since you cannot just create new sub-arrays for the elements, partition method
will need to use another trick to keep track of which elements are greater and
which are lower than the pivot.

The In-place Trick
1. If an element is lower than the pivot, you should swap it with a larger element
   on the left-side of the sub-array.
2. Greater elements should remain where they are.
3. At the end of the partitioning method, the pivot should be swapped with the
   first element of the right partition, consisting of all larger elements, of
   the sub-array.
4. To ensure that you don't swap a small element with another small element, use
   an index to keep track of the small elements that have already been swapped
   into their "place".

Input Format
There will be two lines of input:
n - the size of the array
ar - the n numbers of the array

Output Format
Print the entire array on a new line at the end of every partitioning method.

Constraints
1<=n<=5000
-10000<=x<=10000, x belongs to ar
There are no duplicate numbers.

Sample Input
7
1 3 9 8 2 7 5

Sample Output
1 3 2 5 9 7 8
1 2 3 5 9 7 8
1 2 3 5 7 8 9
