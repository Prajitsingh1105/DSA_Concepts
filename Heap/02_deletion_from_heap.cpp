#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int value){
        size = size+1;
        int index = size;
        arr[index] = value;
        while(index>1){
            int parent  = index/2;
            if(arr[index]>arr[parent]){
                swap(arr[index],arr[parent]);
                index = parent;
            }
            else return;
        }
    }

    void deleteFromHeap(){
        if(size==0){
            cout<<"Heap is empty!"<<endl;
            return;
        }
        arr[1] = arr[size];
        size--;
         
        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;
            if(leftIndex<size && arr[leftIndex]>arr[i]){
                swap(arr[leftIndex],arr[i]);
                i = leftIndex;
            }
            else if(rightIndex<size && arr[rightIndex]>arr[i]){
                swap(arr[rightIndex],arr[i]);
                i = rightIndex;
            }
            else return;
        }
    }

    void print(){
        cout<<"Heap: "<<endl;
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    heap h;
    h.insert(60);
    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(20);
    h.insert(55);
    h.print();
    h.deleteFromHeap();
    h.print();
    return 0;
}