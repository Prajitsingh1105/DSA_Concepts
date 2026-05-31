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

void inOrder(node* root, int& count){
    if(root == NULL) return;
    inOrder(root->left,count);
    if(root->left==NULL || root->right==NULL) count++;
    inOrder(root->right,count);
}

int totalNumberOfLeafNode(node* root){
    int count = 0;
    inOrder(root,count);
    return count;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"Total number of leaf node are: "<<totalNumberOfLeafNode(root);
    return 0;
}