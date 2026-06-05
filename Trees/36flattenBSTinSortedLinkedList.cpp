#include<iostream>
#include<vector>
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

void inOrder(node* root,vector<node*> &vec){
    if(root==NULL) return;
    inOrder(root->left,vec);
    vec.push_back(root);
    inOrder(root->right,vec);
}

node* flattenBST(node* root){
    vector<node*> vec;
    inOrder(root,vec);
    node* newRoot = vec[0];
    node* curr = newRoot;
    for(int i=0;i<vec.size()-1;i++){
        node* temp = vec[i];
        curr->left  = NULL;
        curr->right = temp;
        curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}

void preOrder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    node* root = NULL;
    root = takeInput(root);
    root = flattenBST(root);
    preOrder(root);
    return 0;
}