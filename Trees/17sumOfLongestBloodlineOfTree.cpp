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

void solve(node* root,int sum,int &maxSum,int len,int &maxLen){
    if(root==NULL){
        if(len>maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len==maxLen){
            maxSum = max(sum,maxSum);
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left,sum,maxSum,len+1,maxLen);
    solve(root->right,sum,maxSum,len+1,maxLen);
}

int sumOfLongestBloodlineOfTree(node* root){
    int sum = 0;
    int len = 0;
    int maxSum = INT_MIN;
    int MaxLen = 0;
    solve(root,sum,maxSum,len,MaxLen);
    return maxSum;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"Sum of longest Bloodline of the tree is: "<<sumOfLongestBloodlineOfTree(root);
    return 0;
}