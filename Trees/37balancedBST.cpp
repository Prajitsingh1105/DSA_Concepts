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

void inOrder(node* root,vector<int> &vec){
    if(root==NULL) return;
    inOrder(root->left,vec);
    vec.push_back(root->data);
    inOrder(root->right,vec);
}

node* inOrderToBST(int s,int e,vector<int> &in){
    if(s>e) return NULL;
    int mid = (s+e)/2;
    node* root = new node(in[mid]);
    root->left = inOrderToBST(s,mid-1,in);
    root->right = inOrderToBST(mid+1,e,in);
    return root; 
}

node* balancedBST(node* root){
    vector<int> vec;
    inOrder(root,vec);
    return inOrderToBST(0,vec.size()-1,vec);
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
    root = balancedBST(root);
    cout<<"Balanced BST: "<<endl;
    preOrder(root);
    return 0;
}