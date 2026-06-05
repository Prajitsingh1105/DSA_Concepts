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

bool towSumInBST(node* root,int target){
    vector<int> vec;
    inOrder(root,vec);
    int i = 0, j = vec.size()-1;
    while(i<j){
        if(vec[i]+vec[j]==target) return true;
        else if(vec[i]+vec[j]>target) j--;
        else i++;
    }
    return false;
}

int main(){
    node* root = NULL;
    root = takeInput(root);
    if(towSumInBST(root,50)) cout<<"There exists two numbers whose sum is 50."<<endl;
    else cout<<"There exists no two number whose sum is 50."<<endl;
    return 0;
}