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

//inorder - traversal : LNR
void inOrder(node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//pre-order - traversal : NLR
void preOrder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

//pre-order - traversal : LRN
void postOrder(node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}



int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"InOrder traversal of the tree: "<<endl;
    inOrder(root);
    cout<<endl;
    cout<<"Pre-Order traversal of the tree: "<<endl;
    preOrder(root);
    cout<<endl;
    cout<<"Post-Order traversal of the tree: "<<endl;
    postOrder(root);
    return 0;
}