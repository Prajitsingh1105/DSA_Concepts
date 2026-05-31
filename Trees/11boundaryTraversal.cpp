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

void traverseLeft(node* root,vector<int> &ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)) return;
    ans.push_back(root->data);
    if(root->left) traverseLeft(root->left,ans);
    else traverseLeft(root->right,ans);
}

void traverseRight(node* root,vector<int> &ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;
    if(root->right) traverseRight(root->right,ans);
    else traverseRight(root->left,ans);
    ans.push_back(root->data);
}

void traverseLeafNode(node* root,vector<int> &ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeafNode(root->left,ans);
    traverseLeafNode(root->right,ans);
}

vector<int> boundaryTraversal(node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    ans.push_back(root->data);
    traverseLeft(root->left,ans);
    traverseLeafNode(root->left,ans);
    traverseLeafNode(root->right,ans);
    traverseRight(root->right,ans);
    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    vector<int> res = boundaryTraversal(root);
    cout<<"Boundary traversal : "<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}