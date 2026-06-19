#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <limits.h>
using namespace std;

vector<pair<pair<int, int>, int>> primsMST(
    int n,
    int m,
    vector<pair<pair<int, int>, int>> &graph)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < graph.size(); i++)
    {
        int u = graph[i].first.first;
        int v = graph[i].first.second;
        int w = graph[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> key(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);
    key[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int u = -1;
        for (int v = 0; v <= n; v++)
        {
            if (!mst[v] && key[v] < mini)
            {
                mini = key[v];
                u = v;
            }
        }
        if (u == -1)
            break;
        mst[u] = true;
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (!mst[v] && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for (int i = 1; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main()
{
    vector<pair<pair<int, int>, int>> graph = {
        {{0, 1}, 2},
        {{1, 2}, 3},
        {{2, 4}, 7},
        {{4, 1}, 5},
        {{3, 1}, 8},
        {{3, 0}, 6}};

    int vertices = 4; 
    int edges = 6;
    vector<pair<pair<int, int>, int>> ans =
        primsMST(vertices, edges, graph);
    cout << "Min-Spanning Tree:\n";
    int totalWeight = 0;
    for (auto edge : ans)
    {
        cout << edge.first.first<< " -> "<< edge.first.second<< " : "<< edge.second << endl;
        totalWeight += edge.second;
    }
    cout << "\nTotal Weight = "
         << totalWeight << endl;
}