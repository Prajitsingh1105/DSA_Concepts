#include<iostream>
#include<queue>
using namespace std;

int kthSmallestElement(int arr[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main(){
    int arr[6] = {7,10,4,20,15};
    cout<<"4th smallest element: "<<kthSmallestElement(arr,5,4);
}