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

pair<bool,int> isSumTree(node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL && root->right==NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumTree(root->left);
    pair<bool,int> rightAns = isSumTree(root->right);
    bool left = leftAns.first;
    bool right = rightAns.first;
    bool condition = root->data == leftAns.second + rightAns.second;
    pair<bool,int> ans;
    if(left && right && condition){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else ans.first = false;
    return ans;
}

bool checkForSumTree(node* root){
    return isSumTree(root).first;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    if(checkForSumTree(root)) cout<<"It is a sum tree."<<endl;
    else cout<<"It is not a sum tree."<<endl;
    return 0; 
}