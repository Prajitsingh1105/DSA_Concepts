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
        adjList[v].insert(u);
    }
}

bool isCyclicDFS(unordered_map<int,set<int>> &adjList,
                 unordered_map<int,bool> &visited,
                 int node,
                 int parent) {

    visited[node] = true;

    for(auto neighbour : adjList[node]) {

        if(!visited[neighbour]) {

            bool cycleDetected =
                isCyclicDFS(adjList, visited, neighbour, node);

            if(cycleDetected)
                return true;
        }
        else if(neighbour != parent) {
            return true;
        }
    }

    return false;
}

string cycleDetection(int vertex, vector<pair<int,int>> &edges) {

    unordered_map<int,set<int>> adjList;
    unordered_map<int,bool> visited;

    prepareAdjList(adjList, edges);

    for(int i = 0; i < vertex; i++) {

        if(!visited[i]) {

            bool ans = isCyclicDFS(adjList, visited, i, -1);

            if(ans)
                return "Yes";
        }
    }

    return "No";
}

int main() {

    vector<pair<int,int>> edges = {
        {4,5},
        {5,6},
        {6,8},
        {8,7},
        {7,5},
        {8,9}
    };

    int vertex = 10;

    cout << "Que: Is cycle present?" << endl;
    cout << "Ans: " << cycleDetection(vertex, edges) << endl;

    return 0;
}