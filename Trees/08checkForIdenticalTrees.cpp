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

bool checkForIdenticalTrees(node* root1,node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 == NULL && root2!=NULL || root1!=NULL && root2==NULL)  return false;
    bool left = checkForIdenticalTrees(root1->left,root2->left);
    bool right = checkForIdenticalTrees(root1->right,root2->right);
    bool value = root1->data == root2->data;
    if(left && right && value) return true;
    else return false;
}

int main(){
    node* root1 = NULL;
    root1 = buildTree(root1);
    node* root2 = NULL;
    root2 = buildTree(root2);
    if(checkForIdenticalTrees(root1,root2)) cout<<"Identical trees."<<endl;
    else cout<<"Unidentical trees.";
    return 0;
}