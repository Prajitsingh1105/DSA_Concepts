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

void solve(node* root,int k,int &count,vector<int> path){
    if(root==NULL) return;
    path.push_back(root->data);
    solve(root->left,k,count,path);
    solve(root->right,k,count,path);
    int size = path.size();
    int sum = 0;
    for(int i=size-1;i>=0;i++){
        sum += path[i];
        if(sum==k) count++;
    }
    path.pop_back();
}

int kSumPaths(node* root,int k){
    vector<int> path;
    int count = 0;
    solve(root,k,count,path);
    return count;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"Total numbers of paths with sum 5 is: "<<kSumPaths(root,5);
    return 0;
}