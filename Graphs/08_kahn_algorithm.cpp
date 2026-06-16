#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void prepareAdjList(unordered_map<int,list<int>> &adjList,
                    vector<pair<int,int>> &edges) {

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }
}

vector<int> topologicalOrder(int vertex, vector<pair<int,int>> &edges) {

    unordered_map<int,list<int>> adjList;
    prepareAdjList(adjList,edges);
    vector<int> indegree(vertex+1);
    for(auto i : adjList){
        for(auto j : i.second) indegree[j]++;
    }
    queue<int> q;
    for(int i=1;i<=vertex;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for(auto neigh : adjList[frontNode]){
            indegree[neigh]--;
            if(indegree[neigh]==0) q.push(neigh);
        }
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