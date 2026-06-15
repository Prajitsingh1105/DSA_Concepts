#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
using namespace std;

void prepareAdjList(unordered_map<int,set<int>> &adjList,vector<pair<int,int>> edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

bool isCyclic(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,int node){
    queue<int> q;
    unordered_map<int,int> parent;
    q.push(node);
    parent[node] = 1;
    visited[node] = 1;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        for(auto i : adjList[frontNode]){
            if(visited[i]==true && i!=parent[frontNode]) return true;
            else if(!visited[i]){
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
        }
    }
    return false;
}

string cycleDetection(int vertex,vector<pair<int,int>> edges){
    unordered_map<int,set<int>> adjList;
    unordered_map<int,bool> visited;
    prepareAdjList(adjList,edges);
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bool ans = isCyclic(adjList,visited,i);
            if(ans==true) return "Yes";
        }
    }
    return "No";
}

int main(){
    vector<pair<int,int>> edges = {
        {4,5},
        {5,6},
        {6,8},
        {8,7},
        {7,5},
        {8,9}
    };
    int vertex = 6;
    string ans = cycleDetection(vertex,edges);
    cout<<"Que: Is cycle present?"<<endl;
    cout<<"Ans: "<<ans<<endl;
    return 0;
}
