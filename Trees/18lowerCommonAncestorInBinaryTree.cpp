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

node* lca(node* root,int n1,int n2){
    if(root==NULL) return NULL;
    if(root->data==n1||root->data==n2) return root;
    node* leftAns = lca(root->left,n1,n2);
    node* rightAns = lca(root->right,n1,n2);
    if(leftAns!=NULL && rightAns!=NULL) return root;
    else if(leftAns!=NULL && rightAns==NULL) return leftAns;
    else if(leftAns==NULL && rightAns!=NULL) return rightAns;
    else return NULL;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    node* l = lca(root,8,27);
    cout<<"Lowest common ancestor in the binary tree is: "<<l->data;
    return 0;
}