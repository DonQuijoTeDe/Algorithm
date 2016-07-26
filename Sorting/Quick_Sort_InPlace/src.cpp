#include <vector>
#include <iostream>
using namespace std;

void QuickSort(int,int);

vector<int> vec;

int main() {
    int n,temp;
    cin >> n;

    vec.reserve(n);

    for(int i=0;i<n;i++){
        cin >> temp;
        vec.push_back(temp);
    }

    if(n>1){
        QuickSort(0,vec.size()-1);
    }

    return 0;
}

void QuickSort(int left,int right){

    if(left<right){
        int p=vec[right];
        int index=left;

        //cout << "pivot: " << p << " left: " << left << " right: " << right << "\n";

        for(int i=left;i<right;i++){
            if(vec[i]<=p){
                swap(vec[i],vec[index++]);
            }
        }
        swap(vec[index],vec[right]);

        for(int i=0;i<vec.size();i++){
            cout << vec[i] << " ";
        }
        cout << "\n";

        QuickSort(left,index-1);
        QuickSort(index+1,right);
    }
}
