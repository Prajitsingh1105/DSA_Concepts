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

node* solve(node* root, int &k,int n){
    if(root==NULL) return NULL;
    if(root->data==n) return root;
    node* leftAns = solve(root->left,k,n);
    node* rightAns = solve(root->right,k,n);
    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns==NULL && rightAns!=NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(node* root,int k,int n){
    node* ans = solve(root,k,n);
    if(ans==NULL || ans->data==n) return -1;
    return ans->data;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"2nd ancestor of 4 is: "<<kthAncestor(root,2,4);
    return 0;
}