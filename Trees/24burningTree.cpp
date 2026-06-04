#include<iostream>
#include<map>
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

node* createParentMapping(node* root,int target,map<node*,node*> &nodeToParent){
    node* res = NULL;
    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;
    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front->data == target) res = front;
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(node* root,map<node*,node*> &nodeToParent){
    map<node*,bool> visited;
    queue<node*> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    while(!q.empty()){
        bool flag = 0;
        int size = q.size();
        for(int i=0;i<size;i++){
            node* front = q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left]  = 1;
            }
            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right]  = 1;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]]  = 1;
            }
        }
        if(flag==1) ans++;
    }
    return ans;
}

int minTime(node* root,int target){
    map<node*,node*> nodeToParent;
    node* targetNode = createParentMapping(root,target,nodeToParent);
    int ans = burnTree(targetNode,nodeToParent);
    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    cout<<"Minimum time to burn the tree from target 8 is: "<<minTime(root,8);
    return 0;
}