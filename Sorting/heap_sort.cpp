#include <iostream>
#include <math.h>
using namespace std;

//implement of the max heap tree
void heapify(int* a,int root,int length){
    int leftChild = root*2 + 1;	    // root's left child
    int rightChild = root*2 + 2;    // root's right child
    int maxNode = -1;

    // find the maxNode between the root,leftchild and rightchild
    if(leftChild < length && (a[leftChild] > a[root]))
        maxNode = leftChild;
    else
        maxNode = root;
    if(rightChild < length && (a[rightChild] > a[maxNode]))
        maxNode = rightChild;

    // do the swap if maxNode is not root
    if(maxNode != root){
        cout << "Swap " << a[root] << " and " << a[maxNode] << "\n" ;
        swap(a[root],a[maxNode]);

        for(int i=0;i<10;i++){
            cout << a[i] << " " ;
        }
        cout << "\n\n";

        heapify(a,maxNode,length);
    }
}
// implement of the heap sort
void HeapSort(int a[],const int length){
    for(int i=length/2;i>=0;i--){
        heapify(a,i,length);
    }
    cout << "------------------\n";
    //sort
    for(int i=length-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,0,i);
    }
}

main(){
    //declare the array and its length
    int input[] = {14,51,92,79,45,2,75,70,3,57,4,7,8};
    int length = 13;

    cout << "Before Sort......\n";
    for(int i=0;i<length;i++){
        cout << input[i] << " ";
    }

    cout << "\nSorting Process......\n";

    HeapSort(input,length);

    cout << "\nAfter Sort......\n";
    for(int i=0;i<length;i++){
        cout << input[i] << " ";
    }

    return 0;
}
