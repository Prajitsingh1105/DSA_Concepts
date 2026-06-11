#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newx,int newy, vector<vector<bool>> &vis,vector<vector<int>> &arr,int n){
    if((newx>=0 && newx<n) && (newy>=0 && newy<n) && vis[newx][newy]==0 && arr[newx][newy]==1) return true;
    else return false;
}

void solve(int x,int y,vector<vector<int>> &arr,int n, vector<string> &ans,vector<vector<bool>> &vis,string path){
    // base-case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    // marking visited
    vis[x][y] = 1;;

    // down-move
    if(isSafe(x+1,y,vis,arr,n)) solve(x+1,y,arr,n,ans,vis,path+'D');
    // left-move
    if(isSafe(x,y-1,vis,arr,n)) solve(x,y-1,arr,n,ans,vis,path+'L');
    // right-move
    if(isSafe(x,y+1,vis,arr,n)) solve(x,y+1,arr,n,ans,vis,path+'R');
    // up-move
    if(isSafe(x-1,y,vis,arr,n)) solve(x-1,y,arr,n,ans,vis,path+'U');

    // backtracking
    vis[x][y] = 0;
}

vector<string> searchMaze(vector<vector<int>> &arr,int n){
    vector<string> ans;
    vector<vector<bool>> vis(n,vector<bool>(n,0));
    string path ="";
    if(arr[0][0]==0) return ans;
    solve(0,0,arr,n,ans,vis,path);
    return ans;
}

int main(){
    vector<vector<int>> arr = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,0,0},
        {0,1,1,1}
    };
    int n = 4;
    vector<string> ans = searchMaze(arr,n);
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}