#include <iostream>
using namespace std;

void QuickSort(int* a,int left,int right){

    if(left<right){
        //divide(partition)
        int pivot = a[(left+right)/2],//choose pivot
            i = left-1,
            j = right+1;
        while(i<j){
            do ++i;while(a[i]<pivot);
            do --j;while(a[j]>pivot);
            if(i<j) swap(a[i],a[j]);

            for(int i=0;i<10;i++){
                cout << a[i] << " ";
            }
            cout << "\n" ;
        }
        //then conquer
        QuickSort(a,left,i-1);
        QuickSort(a,j+1,right);
    }
}

main(){
    int non_ordered[] ={26,5,37,1,61,11,59,15,48,19};//declare of the array

    cout << "Before sort ....\n";
    for(int i=0;i<10;i++){
        cout << non_ordered[i] << " " ;
    }
    cout << "\n";
    cout << "Soring Process....\n";

    QuickSort(non_ordered,0,9); //do quicksort

    cout << "After sort ....\n";
    for(int i=0;i<10;i++){
        cout << non_ordered[i] << " " ;
    }

    return 0;
}
