#include<iostream>
#include<queue>
using namespace std;

int minCost(int arr[],int n){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int cost = 0;
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        cost+=sum;
        pq.push(sum);
    }
    return cost;
}

int main(){
    int arr[4] = {4,2,3,6};
    cout<<"Minimum Cost of the rope required is: "<<minCost(arr,4);
}