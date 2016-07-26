#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, K, Q, temp, shift, query;
    cin >> N >> K >> Q;

    vector<int> vec;
    vec.reserve(N);
    for(int i = 0; i < N; i++){
        cin >> temp;
        vec.push_back(temp);
    }

    // Algorithm
    shift = K % N;
    for(int i = 0; i < Q; i++){
        cin >> query;
        if(query - shift < 0){
            query = N + (query - shift);
        }
        else{
            query = query - shift;
        }
        cout << vec[query] << "\n";
    }

    return 0;
}
