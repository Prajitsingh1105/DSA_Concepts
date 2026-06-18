#include<iostream>
#include<vector>
#include<list>
#include<set>
#include<unordered_map>
#include<limits.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec,int vertices,int edges,int source){
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back({v,w});
    }
    vector<int> dis(vertices,INT_MAX);
    set<pair<int,int>> st;
    dis[source]=0;
    st.insert({0,source});
    while(!st.empty()){
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        st.erase(st.begin());
        for(auto neigh: adj[topNode]){
            int neighbour = neigh.first;
            int weight = neigh.second;
            if(nodeDistance + weight < dis[neighbour]){
                auto record = st.find({dis[neighbour],neighbour});
                if(record != st.end()){
                    st.erase(record);
                }
                dis[neighbour] = nodeDistance + weight;
                st.insert({dis[neighbour],neighbour});
            }
        }
    }
    return dis;
}

int main(){
    vector<vector<int>> data = {
        {0,1,7},
        {0,2,1},
        {0,3,2},
        {1,0,7},
        {1,2,3},
        {1,3,5},
        {1,4,1},
        {2,0,1},
        {2,1,3},
        {3,0,2},
        {3,1,5},
        {3,4,7},
        {4,1,1},
        {4,3,7}
    };
    int vertices = 5;
    int edges = 14;
    int source = 0;
    vector<int> ans;
    ans = dijkstra(data,vertices,edges,source);
    cout<<"Smallest path by Dijkstra's Algo: "<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}