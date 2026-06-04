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

void flatten(node* root){
    node* current = root;
    while(current!=NULL){
        if(current->left){
            node* pred = current->left;
            while(pred->right){
                pred = pred -> right;
            }
            pred -> right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}

void preOrder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    flatten(root);
    cout<<"Flatten tree : "<<endl;
    preOrder(root);
    return 0;
}