#include <iostream>
#include <algorithm>
using namespace std;

void RadixSort(int* data,const int length,const int n){
    int radix=1; // radix = 1, 10, 100,...
    int buckets[length][length],
        counter[length];
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            buckets[i][j] = 0;
        }
        counter[i] = 0;
    }
    //allocate
    while(radix <= n){
        for(int i=0;i<length;i++){
            int LSD = data[i]/radix %10; //to find the digit that we need right now
            buckets[LSD][counter[LSD]++] = data[i];
        }
        //put the data(buckets) that is sorted after one turn back of the array
        //and then we can go next turn
        int index = 0;
        for(int i=0;i<length;i++){
            if(counter[i]!=0){
               for(int j=0;j<counter[i];j++){
                   data[index++] = buckets[i][j];
               }
            }
            counter[i]=0;
        }
        radix *= 10;
    }
}

main(){
    //declare of the array and its length
    int input[] = {999,876,765,654,543,432,321,210,109,1};
    int length = 10;
    int n = 100;

    cout << "Before Sorting.....\n";
    for(int i=0;i<length;i++){
        cout << input[i] << " ";
    }
    cout << "\n";

    RadixSort(input,length,n); //do RadixSort

    cout << "After Sorting......\n";
     for(int i=0;i<length;i++){
        cout << input[i] << " ";
    }
    cout << "\n";

    return 0;
}
