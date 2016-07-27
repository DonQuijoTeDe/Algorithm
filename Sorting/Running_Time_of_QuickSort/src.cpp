#include <vector>
#include <iostream>
using namespace std;

void QuickSort(int,int);
void InsertionSort(int);

vector<int> vq;
vector<int> vi;
int count_quicksort;
int count_insertionsort;

int main() {
    int n,temp;
    count_quicksort = 0;
    count_insertionsort = 0;

    cin >> n;
    vq.reserve(n);
    vi.reserve(n);
    for(int i = 0; i < n; i++){
        cin >> temp;
        vq.push_back(temp);
    }
    vi = vq;

    QuickSort(0, n - 1);
    InsertionSort(n);

    cout << count_insertionsort - count_quicksort;

    return 0;
}

void QuickSort(int left, int right){
    if(left < right){
        int p = vq[right];
        int index = left;

        for(int i = left; i < right; i++){
            if(vq[i] <= p){
                swap(vq[i], vq[index++]);
                count_quicksort++;
            }
        }
        swap(vq[index], vq[right]);
        count_quicksort++;

        QuickSort(left, index - 1);
        QuickSort(index + 1, right);
    }
}

void InsertionSort(int n){
    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            if(vi[j] < vi[j - 1]){
                swap(vi[j], vi[j - 1]);
                count_insertionsort++;
            }
        }
    }
}
