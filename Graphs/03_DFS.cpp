#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(int node,
         unordered_map<int,list<int>> &adj,
         unordered_map<int,bool> &visited,
         vector<int> &component){

    component.push_back(node);
    visited[node] = true;

    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(i,adj,visited,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, vector<vector<int>> edges){

    unordered_map<int,list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,adj,visited,component);
            ans.push_back(component);
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> edges = {
        {0,4},
        {4,2},
        {2,3},
        {3,5},
        {5,1},
        {1,4}
    };
    int V = 6;
    vector<vector<int>> ans = depthFirstSearch(V,edges);
    cout << "DFS: \n";
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}