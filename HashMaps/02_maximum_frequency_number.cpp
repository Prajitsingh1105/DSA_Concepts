#include<iostream>
#include<unordered_map>
using namespace std;

int maxFrequencyNumber(int arr[],int size){
    unordered_map<int,int> m;
    int maxFreq = 0;
    int maxAns = 0;
    for(int i=0;i<size;i++){
        m[arr[i]]++;
        maxFreq = max(maxFreq,arr[i]);
    }
    for(int i=0;i<size;i++){
        if(maxFreq == m[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main(){
    int arr[5] = {1,2,3,1,2};
    int size = 5;
    cout<<"Max-Frequency number is: "<<maxFrequencyNumber(arr,size)<<endl; 
}
