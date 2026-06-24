#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    for (auto neigh : adj[node])
    {
        if (neigh == parent)
            continue;
        if (!vis[neigh])
        {
            dfs(neigh, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[neigh]);
            if (low[neigh] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neigh);
                result.push_back(ans);
            }
        }
        else
        {
            low[node] = min(low[node], disc[neigh]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }
    vector<vector<int>> result;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(i, parent, timer, disc, low, result, adj, vis);
    }
    return result;
}

int main()
{
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {2, 3}, 
        {3, 4}, 
        {4, 5}, 
        {5, 6}, 
        {6, 7}, 
        {7, 8},
        {8, 9},
        {9, 7} 
    };
    int v = 10;
    int e = 11;
    vector<vector<int>> ans;
    ans = findBridges(edges, v, e);
    cout << "Bridge edges are: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{" << ans[i][0] << "," << ans[i][1] << "}" << endl;
    }
    cout << endl;
    return 0;
}