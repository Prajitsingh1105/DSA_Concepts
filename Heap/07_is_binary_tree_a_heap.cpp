#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cout<<"Enter the data(-1 if null): ";
    cin>>data;
    if(data == -1){
        return NULL;
    }
    root = new node(data);
    cout<<"Enter the data left to "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data right to "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

int totalCount(node* root){
    if(root == NULL) return 0;
    int count = 1 + totalCount(root->left) + totalCount(root->right);
    return count;
}

bool isCBT(node* root,int index,int totalCnt){
    if(root==NULL) return true;
    if(index>=totalCnt) return false;
    else{
        bool left = isCBT(root->left,2*index+1,totalCnt);
        bool right = isCBT(root->right,2*index+2,totalCnt);
        return left&&right;
    }
}

bool isMaxOrder(node* root){
    if(root->left==NULL && root->right==NULL) return true;
    if(root->right == NULL) return root->data>root->left->data;
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return left && right && (root->data>root->left->data && root->data>root->right->data);
    }
}

bool isHeap(node* root){
    int index = 0;
    int totalCnt = totalCount(root);
    if(isCBT(root,index,totalCnt) && isMaxOrder(root)) return true;
    else return false;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    if(isHeap(root)) cout<<"The tree is a Heap."<<endl;
    else cout<<"The tree is'nt a Heap."<<endl;
    return 0;
}