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

void preOrder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

pair<int,int> predSucc(node* root,int key){
    node* temp = root;
    int pred = -1;
    int succ = -1;
    while(temp->data!=key){
        if(temp->data>key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }
    node* leftTree = temp->left;
    while(leftTree!=NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    node* rightTree = temp->right;
    while(rightTree!=NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    pair<int,int> ans = make_pair(pred,succ);
    return ans;
}

int main(){
    node* root = NULL;
    root = takeInput(root);
    preOrder(root);
    cout<<endl;
    pair<int,int> preAnsSuc = predSucc(root,40);
    cout<<"Predecessor of 40: "<<preAnsSuc.first<<endl;
    cout<<"Successor of 40: "<<preAnsSuc.second<<endl;
    return 0;
}