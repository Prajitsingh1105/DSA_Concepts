#include<iostream>
#include<algorithm>
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

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;
    return ans;
}

int diameter(node* root){
    if(root == NULL){
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left)+height(root->right)+1;

    int ans = max(op1,max(op2,op3));
    return ans;
}

//optimised

pair<int,int> diameterOptimised(node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    pair<int,int> left = diameterOptimised(root->left);
    pair<int,int> right = diameterOptimised(root->right);
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second  +1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(op1,op2) + 1;
    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    pair<int,int> diameter;
    diameter.first = diameterOptimised(root).first;
    cout<<"Diameter of tree: "<<diameter.first;
    return 0;
}