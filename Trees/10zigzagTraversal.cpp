#include<iostream>
#include<vector>
#include<queue>
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

vector<int> zigzagTraversal(node* root){
    vector<int> res;
    if(root==NULL) return res;
    queue<node*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++){
            node* front = q.front();
            q.pop();
            int index = leftToRight ? i : size -i -1;
            ans[index] = front->data;
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        leftToRight = !leftToRight;
        for(auto i : ans){
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    vector<int> res;
    res = zigzagTraversal(root);
    cout<<"Zigzag traversal :"<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}