#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector<int> &ivector){
    // if sequence only contain one element, it is already a sorted sequence
    if(ivector.size()==1){
        return ;
    }
    //divide sequence
    vector<int> left(ivector.begin(),ivector.begin()+ivector.size()/2),
                right(ivector.begin()+ivector.size()/2,ivector.end());

                for(int i=0;i<left.size();i++){
                cout << left[i] << " ";
                }
                cout << "\n";
                for(int i=0;i<right.size();i++){
                        cout << right[i] << " ";
                }
                cout << "\n";

    // sort sub-sequence
    MergeSort(left);
    MergeSort(right);

    cout << "\nivector.size = " << ivector.size();
    cout << "\nleft.size = " << left.size();
    cout << "\nright.size = " << right.size()<< "\n";
    // i point to origin, j point to left, k point to right
    for(int i=0,j=0,k=0;i<ivector.size();++i){
        // if left is less than right or right part is end
        if((j!=left.size() && left[j]<right[k]) || k==right.size()){
            cout << "Move " << left[j] << " to " << "ivector[" << i << "]" ;
            ivector[i]=left[j++];
        }
        // if right is less than or equal to left or left part is end
        else{
            cout << "Move " << right[k] << " to " << "ivector[" << i << "]" ;
            ivector[i]=right[k++];
        }
        cout << "\n";
    }
    cout << "\n" ;
}

main(){
    int inputList[] = {26,5,77,1,61,11,59,15,48,19}; //declare of the array
    vector<int> ivector(inputList,inputList+10); // use declared array to initialize the vector

    cout << "Before Sort ......\n";
    for(int i=0;i<ivector.size();i++){
        cout << ivector[i] << " ";
    }

    cout << "\n\nSorting Process......\n";

    MergeSort(ivector); //do MergeSort

    cout <<"\nAfter Sort...\n";
    for(int i=0;i<ivector.size();i++){
        cout << ivector[i] << " ";
    }

    return 0;
}
