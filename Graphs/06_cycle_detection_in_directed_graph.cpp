#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
using namespace std;

void prepareAdjList(unordered_map<int,set<int>> &adjList,
                    vector<pair<int,int>> &edges) {

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
    }
}

bool isCyclicDFS(unordered_map<int,set<int>> &adjList,
                 unordered_map<int,bool> &visited,
                 int node,
                 unordered_map<int,bool> &dfsVisited) {

    visited[node] = true;
    dfsVisited[node] = true;
    for(auto neighbour : adjList[node]) {
        if(!visited[neighbour]) {
            bool cycleDetected =
                isCyclicDFS(adjList, visited, neighbour, dfsVisited);

            if(cycleDetected)
                return true;
        }
        else if(dfsVisited[neighbour]) {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

string cycleDetection(int vertex, vector<pair<int,int>> &edges) {

    unordered_map<int,set<int>> adjList;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;

    prepareAdjList(adjList, edges);
    for(int i = 0; i < vertex; i++) {
        if(!visited[i]) {
            bool ans = isCyclicDFS(adjList, visited, i, dfsVisited);
            if(ans)
                return "Yes";
        }
    }
    return "No";
}

int main() {

    vector<pair<int,int>> edges = {
        {1,2},
        {2,3},
        {3,7},
        {3,8},
        {8,7},
        {2,4},
        {4,5},
        {5,6},
        {6,4}
    };

    int vertex = 8;

    cout << "Que: Is cycle present?" << endl;
    cout << "Ans: " << cycleDetection(vertex, edges) << endl;

    return 0;
}