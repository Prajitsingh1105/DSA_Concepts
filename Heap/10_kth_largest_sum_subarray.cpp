#include<iostream>
#include<queue>
using namespace std;

int kthLargestSumSubarray(int arr[],int size,int k){
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<size;i++){
        int sum = 0;
        for(int j=i;j<size;j++){
            sum+=arr[j];
            if(minHeap.size()<k) minHeap.push(sum);
            else{
                if(sum>minHeap.top()){
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    return minHeap.top();
}

int main(){
    int arr[] = {1,2,4,6,3};
    cout<<"3rd largest sum of sub-array is: "<<kthLargestSumSubarray(arr,5,3)<<endl;
}