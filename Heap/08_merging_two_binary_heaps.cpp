#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &arr,int n,int i){
    int largest  = i;
    int left = 2*i + 1;
    int right  = 2*i + 2;
    if(left<n && arr[largest]<arr[left]) largest = left;
    if(right<n && arr[largest]<arr[right]) largest = right;
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

vector<int> mergedHeap(vector<int> &a,vector<int> &b){
    vector<int> ans;
    for(auto i : a){
        ans.push_back(i);
    }
    for(auto i : b){
        ans.push_back(i);
    }

    int size = ans.size();
    for(int i=size/2-1;i>=0;i--){
        heapify(ans,size,i);
    }
    return ans;
}

int main(){
    vector<int> a = {10,5,6,2};
    vector<int> b = {12,7,9};
    cout<<"Merged Heap: "<<endl;
    vector<int> merged = mergedHeap(a,b);
    for(auto i : merged){
        cout<<i<<" ";
    }
    return 0;
}