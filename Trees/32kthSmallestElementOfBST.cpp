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

node* insertToBST(node* root,int d){
    if(root==NULL){
        root = new node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertToBST(root->right,d);
    }
    else{
        root->left = insertToBST(root->left,d);
    }
    return root;
}

node* takeInput(node* &root){
    int data;
    cout<<"Enter the node: ";
    cin>>data;
    while(data!=-1){
        root = insertToBST(root,data);
        cin>>data;
    }
    return root;
}

void preOrder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int kthSmallestElement(node* root,int &i,int k){
    if(root==NULL) return -1;
    int left = kthSmallestElement(root->left,i,k);
    if(left!=-1) return left;
    i++;
    if(i==k) return root->data;
    return kthSmallestElement(root->right,i,k);
}

int main(){
    node* root = NULL;
    root = takeInput(root);
    preOrder(root);
    cout<<endl;
    int i = 0;
    cout<<"3rd smallest element is: "<<kthSmallestElement(root,i,3);
    return 0;
}