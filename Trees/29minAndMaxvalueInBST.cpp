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

int minValue(node* root){
    if(root==NULL) return -1;
    node* temp = root;
    while(temp->left!=NULL) temp=temp->left;
    return temp->data;
}

int maxValue(node* root){
    if(root==NULL) return -1;
    node* temp = root;
    while(temp->right!=NULL) temp=temp->right;
    return temp->data;
}

int main(){
    node* root = NULL;
    root = takeInput(root);
    preOrder(root);
    cout<<endl;
    cout<<"Min-value of the BST is: "<<minValue(root)<<endl;
    cout<<"Max-value of the BST is: "<<maxValue(root)<<endl;
    return 0;
}