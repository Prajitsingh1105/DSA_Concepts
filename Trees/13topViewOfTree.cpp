#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

vector<int> topView(node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    map<int,int> topNode;
    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second;
        if(topNode.find(hd)==topNode.end()) topNode[hd]=frontNode->data;
        if(frontNode->left) q.push(make_pair(frontNode->left,hd-1));
        if(frontNode->right) q.push(make_pair(frontNode->right,hd+1));
    }
    for(auto i: topNode){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"Top-View : "<<endl;
    vector<int> res = topView(root);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}