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
        if(in[i] == element) return i;
    }
    return -1;
}

node* solve(int in[], int pre[], int &index,
            int inorderStart, int inorderEnd, int n){

    if(index >= n || inorderStart > inorderEnd)
        return NULL;

    int element = pre[index++];
    node* root = new node(element);

    int position = findPosition(in, inorderStart, inorderEnd, element);

    root->left = solve(in, pre, index, inorderStart, position - 1, n);
    root->right = solve(in, pre, index, position + 1, inorderEnd, n);

    return root;
}

node* buildTree(int in[], int pre[], int n){
    int preOrderIndex = 0;
    return solve(in, pre, preOrderIndex, 0, n - 1, n);
}

void postOrder(node* root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};

    node* root = buildTree(in, pre, 6);

    postOrder(root);
}