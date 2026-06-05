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

node* inOrderToBST(int s,int e,vector<int> &in){
    if(s>e) return NULL;
    int mid = (s+e)/2;
    node* root = new node(in[mid]);
    root->left = inOrderToBST(s,mid-1,in);
    root->right = inOrderToBST(mid+1,e,in);
    return root; 
}

vector<int> mergeArrays(vector<int> &a,vector<int> &b){
    vector<int> ans(a.size()+b.size());
    int i=0,j=0;
    int k=0;
    while (i<a.size() && j<b.size())
    {   
        if(a[i]<b[i]){
            ans[k++] = a[i];
            i++;
        }
        else{
            ans[k++] = b[j];
            j++;
        }
    }
    while(i<a.size()){
        ans[k++] = a[i];
        i++;
    }
    while(j<b.size()){
        ans[k++] = b[j];
        j++;
    }
    return ans;
}

node* mergeBST(node* root1,node* root2){
    vector<int> vec1;
    inOrder(root1,vec1);
    vector<int> vec2;
    inOrder(root2,vec2);
    vector<int> mergedVec = mergeArrays(vec1,vec2);
    int s = 0, e = mergedVec.size()-1;
    return inOrderToBST(s,e,mergedVec);
}

void preOrder(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    cout<<"BST1 : "<<endl;
    node* root1 = NULL;
    root1 = takeInput(root1);
    cout<<"BST2 : "<<endl;
    node* root2 = NULL;
    root2 = takeInput(root2);
    node* mergedBST = mergeBST(root1,root2);
    cout<<"Merged BST: "<<endl;
    preOrder(mergedBST);
    return 0;
}