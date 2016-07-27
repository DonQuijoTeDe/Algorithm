#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long counter;

void MergeSort(vector<int> &);

int main() {
    int Case,N,i,temp;

    vector<int> vec;

    cin >> Case;
    while(Case--){
        cin >> N;
        counter = 0;
        vec.clear();
        vec.reserve(N);
        for(i=0;i<N;i++){
            cin >> temp;
            vec.push_back(temp);
        }

        MergeSort(vec);

        cout << counter << "\n";
    }
    
    return 0;
}

void MergeSort(vector<int> &vec){
    // If the sequence only contains an element
    if(vec.size() == 1){
        return;
    }

    // Divide the sequence into left and right part
    vector<int> left(vec.begin(),vec.begin()+vec.size()/2),
                right(vec.begin()+vec.size()/2,vec.end());

    // Sort the sub-sequence
    MergeSort(left);
    MergeSort(right);

    // i points to vec, j points to left, k points to right
    for(int i=0,j=0,k=0;i<vec.size();i++){
        // If left is less than right or right part is end
        if((j!=left.size() && left[j]<=right[k]) || k==right.size()){
            //cout << "Move " << left[j] << " to " << "ivector[" << i << "]" ;
            vec[i] = left[j++];
        }
        // If right is less than left or left part is end
        else{
            //cout << "Move " << right[k] << " to " << "ivector[" << i << "]" ;
            vec[i] = right[k++];
            counter += left.size()-j;
        }
    }
}
