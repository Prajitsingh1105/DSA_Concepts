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

node* deleteNode(node* root,int val){
    if(root==NULL) return root;
    if(root->data == val){
        //zero child
        if(root->left==NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //one child
        //left child
        if(root->left!=NULL && root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        //two child
        if(root->right!=NULL && root->left!=NULL){
            //applying least from right part
            int mini = minValue(root->right);
            root->data = mini;
            root->right = deleteNode(root->right,mini);
            return root;
        }
    }
    else if(root->data>val){
        root->left = deleteNode(root->left,val);
        return root;
    }
    else{
        root->right = deleteNode(root->right,val);
        return root;
    }
}

int main(){
    node* root = NULL;
    root = takeInput(root);
    preOrder(root);
    cout<<endl;
    root = deleteNode(root,40);
    cout<<"New BST: "<<endl;
    preOrder(root);
    return 0;
}