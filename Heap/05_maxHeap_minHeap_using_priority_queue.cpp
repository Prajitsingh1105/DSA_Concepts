#include<iostream>
#include<queue>
using namespace std;

int main(){
    //Max-Heap
    priority_queue<int> maxHeap;
    maxHeap.push(5);
    maxHeap.push(2);
    maxHeap.push(4);
    maxHeap.push(3);
    maxHeap.push(1);
    cout<<"Max-Heap: "<<endl;
    cout<<"Top element: "<<maxHeap.top()<<endl;
    maxHeap.pop();
    cout<<"Top element: "<<maxHeap.top()<<endl;
    if(maxHeap.empty()) cout<<"Max_heap is empty!"<<endl;
    else cout<<"Max-Heap is not empty!"<<endl;

    cout<<"============================"<<endl;
    //Min-Heap
    priority_queue<int,vector<int>,greater<int>> minHeap;
    minHeap.push(5);
    minHeap.push(2);
    minHeap.push(4);
    minHeap.push(3);
    minHeap.push(1);
    cout<<"Min-Heap: "<<endl;
    cout<<"Top element: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Top element: "<<minHeap.top()<<endl;
    if(minHeap.empty()) cout<<"Max_heap is empty!"<<endl;
    else cout<<"Min-Heap is not empty!"<<endl;

}