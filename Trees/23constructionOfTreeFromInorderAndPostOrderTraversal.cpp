#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = right = NULL;
    }
};

int findPosition(int in[], int start, int end, int element){
    for(int i = start; i <= end; i++){
        if(in[i] == element)
            return i;
    }
    return -1;
}

node* solve(int in[], int post[], int &index,
            int inorderStart, int inorderEnd, int n){

    if(index < 0 || inorderStart > inorderEnd)
        return NULL;

    int element = post[index--];
    node* root = new node(element);

    int position = findPosition(in, inorderStart, inorderEnd, element);

    root->right = solve(in, post, index,
                        position + 1, inorderEnd, n);

    root->left = solve(in, post, index,
                       inorderStart, position - 1, n);

    return root;
}

node* buildTree(int in[], int post[], int n){
    int postIndex = n - 1;
    return solve(in, post, postIndex, 0, n - 1, n);
}

void preorder(node* root){
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    int inorder[] = {3,1,4,0,5,2};
    int postorder[] = {3,4,1,5,2,0};

    node* root = buildTree(inorder, postorder, 6);

    preorder(root);

    return 0;
}