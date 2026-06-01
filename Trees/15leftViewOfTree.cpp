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

void solve(node* root,vector<int> &ans,int level){
    if(root==NULL) return;
    if(level==ans.size()) ans.push_back(root->data);
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}

vector<int> leftView(node* root){
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"Left-View : "<<endl;
    vector<int> res = leftView(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}