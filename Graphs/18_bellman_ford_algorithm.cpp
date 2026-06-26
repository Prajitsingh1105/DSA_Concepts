#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int bellman_ford(int v,vector<vector<int>> &edges,int src, int desti){
    vector<int> dist(v+1,INT_MAX);
    dist[src] = 0;

    for(int i=1;i<=v;i++){
        for(auto edge: edges){
            int u = edge[0];
            int v1 = edge[1];
            int wt = edge[2];
            if(dist[u] != INT_MAX && dist[u] + wt < dist[v1]){
                dist[v1] = dist[u] + wt;
            }
        }
    }
    for(auto edge: edges){
        int u = edge[0];
        int v1 = edge[1];
        int wt = edge[2];
        if(dist[u] != INT_MAX && dist[u] + wt < dist[v1]){
            cout << "Negative weight cycle detected!" << endl;
            return -1;
        }
    }
    return dist[desti];
}

int main(){
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 3, -1},
        {1,3, 2}
    };
    int v = 3;
    int src = 1;
    int desti = 3;
    int result = bellman_ford(v, edges, src, desti);
    if(result != -1){
        cout << "Shortest distance from vertex " << src << " to vertex " << desti << " is " << result << endl;
    }
}