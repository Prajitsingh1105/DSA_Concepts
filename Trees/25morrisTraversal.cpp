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

vector<int> morrisTraversal(node* root) {
    vector<int> res;
    node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            res.push_back(curr->data);
            curr = curr->right;
        }
        else {
            node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    vector<int> ans = morrisTraversal(root);
    cout<<"Morris Traversal: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}