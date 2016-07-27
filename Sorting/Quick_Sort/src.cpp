#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &);

int main(){
    int n,temp;
    cin >> n;

    vector<int> vec;
    vec.reserve(n);
    for(int i=0;i<n;i++) {
        cin >> temp;
        vec.push_back(temp);
    }

    if(n>1){
        quickSort(vec);
    }

    return 0;
}

void quickSort(vector<int> &vec) {
    if(vec.size()<=1){
        return;
    }

    int p=vec[0];
    vector<int> left;
    vector<int> right;
    left.reserve(vec.size());
    right.reserve(vec.size());

    // Divide
    for(int i=1;i<vec.size();i++){
        if(vec[i]<=p){
            left.push_back(vec[i]);
        }
        else{
            right.push_back(vec[i]);
        }
    }

    // Conquer
    quickSort(left);
    quickSort(right);

    // Merge
    copy(left.begin(),left.end(),vec.begin());
    vec[left.size()] = p;
    copy(right.begin(),right.end(),vec.begin()+left.size()+1);

    // Print the sorted subarray
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << "\n";
}
