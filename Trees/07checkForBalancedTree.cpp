#include<iostream>
#include<algorithm>
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

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;
    return ans;
}

bool checkForBalancedTree(node* root){
    if(root == NULL) return true;
    bool left = checkForBalancedTree(root->left);
    bool right = checkForBalancedTree(root->right);
    bool diff = abs(height(root->left)-height(root->right)) <=1;
    if(left && right && diff) return true;
    else return false;
}


//optimised - O(n)
pair<bool,int> checkForBalancedTreeOptimised(node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    pair<bool,int> checkLeft = checkForBalancedTreeOptimised(root->left);
    pair<bool,int> checkRight = checkForBalancedTreeOptimised(root->right);
    bool left = checkLeft.first;
    bool right = checkRight.first;
    bool diff = abs(checkLeft.second - checkRight.second) <=1;
    pair<bool,int> ans;
    ans.second = max(checkLeft.second,checkRight.second) +1;
    if(left && right && diff) ans.first = true;
    else ans.first = false;
    return ans;
}

int main(){
    node* root = NULL;
    root = buildTree(root);
    if(checkForBalancedTree(root)) cout<<"It is a balanced Tree!!";
    else cout<<"It is not a balanced tree!!";\
    cout<<endl;
    if(checkForBalancedTreeOptimised(root).first) cout<<"It is a balanced Tree!! Checked in O(n).";
    else cout<<"It is not a balanced tree!! Checked in O(n).";
    return 0;
}