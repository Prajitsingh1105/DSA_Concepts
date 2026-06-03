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

pair<int,int> solve(node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> leftAns = solve(root->left);
    pair<int,int> rightAns = solve(root->right);
    pair<int,int> res;
    res.first = root->data + leftAns.second + rightAns.second;
    res.second = max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second);
    return res;
}

int maxSumOfNonAdjacentNodes(node* root){
    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"Max Sum of non-adjacent nodes are: "<<maxSumOfNonAdjacentNodes(root);
    return 0;
}