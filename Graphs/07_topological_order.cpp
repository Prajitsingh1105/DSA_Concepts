#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
using namespace std;

void prepareAdjList(unordered_map<int,list<int>> &adjList,
                    vector<pair<int,int>> &edges) {

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }
}

void topoSort(int node,unordered_map<int,bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adjList){
    visited[node] = 1;
    for(auto i : adjList[node]){
        if(!visited[i]) topoSort(i,visited,s,adjList);
    }
    s.push(node);
}

vector<int> topologicalOrder(int vertex, vector<pair<int,int>> &edges) {

    unordered_map<int,list<int>> adjList;
    unordered_map<int,bool> visited;
    stack<int> s;
    prepareAdjList(adjList, edges);
    for(int i = 1; i <= vertex; i++) {
        if(!visited[i]) {
            topoSort(i,visited,s,adjList);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main() {

    vector<pair<int,int>> edges = {
        {1,2},
        {1,3},
        {2,4},
        {3,4},
        {4,5},
        {4,6},
        {5,6}
    };

    int vertex = 6;
    vector<int> ans;
    ans = topologicalOrder(vertex,edges);
    cout<<"Topological Order: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}