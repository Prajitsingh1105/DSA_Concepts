#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int kruskal(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end());

    DSU ds(n);

    int mstWeight = 0;

    for (auto &it : edges) {
        int wt = it[0];
        int u = it[1];
        int v = it[2];

        if (ds.findParent(u) != ds.findParent(v)) {
            mstWeight += wt;
            ds.unionByRank(u, v);
        }
    }

    return mstWeight;
}

int main() {
    int n = 4;

    vector<vector<int>> edges = {
        {10, 0, 1},
        {6, 0, 2},
        {5, 0, 3},
        {15, 1, 3},
        {4, 2, 3}
    };

    cout << kruskal(n, edges);

    return 0;
}