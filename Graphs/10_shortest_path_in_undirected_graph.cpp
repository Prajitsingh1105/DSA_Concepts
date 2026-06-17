#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void prepareAdjList(unordered_map<int,list<int>> &adjList,vector<pair<int,int>> edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}


vector<int> shortestPath(int vertex,vector<pair<int,int>> edges,int start,int destination){
    unordered_map<int,list<int>> adjList;
    unordered_map<int,bool> visited;
    prepareAdjList(adjList,edges);
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(start);
    parent[start] = -1;
    visited[start] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i : adjList[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }
    vector<int> ans;
    int currNode = destination;
    ans.push_back(destination);
    while(currNode!=start){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<pair<int,int>> edges = {
        {1,2},
        {1,3},
        {1,4},
        {2,5},
        {5,8},
        {3,8},
        {4,6},
        {6,7},
        {7,8}
    };
    int vertex = 6;
    int start = 1;
    int destination = 8;
    vector<int> ans = shortestPath(vertex,edges,start,destination);
   cout<<"Shortest Path: "<<endl;
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" -> ";
   }
   cout<<"NULL"<<endl;
    return 0;
}
