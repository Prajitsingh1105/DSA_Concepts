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

void preOrder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// bool validateBST(node* root){
//     if(root==NULL) return true;
//     if(root->left==NULL || root->right==NULL) return true;
//     if(root->data<root->left->data){
//         return false;
//     }
//     else if(root->data>root->right->data){
//         return false;
//     }
//     bool left = validateBST(root->left);
//     bool right = validateBST(root->right);
//     if(left&&right) return true;
//     else return false;
// }

bool validateBST(node* root,int min,int max){
    if(root==NULL) return true;
    if(root->data>=min && root->data<=max){
        return validateBST(root->left,min,root->data) && validateBST(root->right,root->data,max);
    }
    else return false;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    preOrder(root);
    cout<<endl;
    if(validateBST(root,INT_MIN,INT_MAX)) cout<<"It is a BST."<<endl;
    else cout<<"It is not a BST."<<endl;
    return 0;
}