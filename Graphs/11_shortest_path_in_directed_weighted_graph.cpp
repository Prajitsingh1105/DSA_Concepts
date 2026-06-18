#include<iostream>
#include<stack>
#include<vector>
#include<list>
#include<unordered_map>
#include<limits.h>
using namespace std;

class Graph {
    public: 
        unordered_map<int,list<pair<int,int>>> adj;

        void addEdge(int u,int v,int weight){
            pair<int,int> p = make_pair(v,weight);
            adj[u].push_back(p);
        }

        void printAdj(){
            for(auto i : adj){
                cout<<i.first<<" -> ";
                for(auto j : i.second){
                    cout<<"("<<j.first<<","<<j.second<<"),";
                }
                cout<<endl;
            }
            cout<<endl;
        }

        void dfs(int node,unordered_map<int,bool> &vis,stack<int> &s){
            vis[node] = true;
            for(auto neigh : adj[node]){
                if(!vis[neigh.first]){
                    dfs(neigh.first,vis,s);
                }
            }
            s.push(node);
        }

        void getShortestPath(int src,vector<int> &dis,stack<int> &s){
            dis[src] = 0;
            while(!s.empty()){
                int top = s.top();
                s.pop();

                if(dis[top] != INT_MAX){
                    for(auto i : adj[top]){
                        if(dis[top] + i.second < dis[i.first]) dis[i.first] = dis[top] + i.second;
                    }
                }
            }
        }
};


int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();
    int n = 6;
    unordered_map<int,bool> vis;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!vis[i]) g.dfs(i,vis,s);
    }

    int src = 3;
    vector<int> dis(n);
    for(int i=0;i<n;i++){
        dis[i] = INT_MAX;
    }
    g.getShortestPath(src,dis,s);
    cout<<"Shortest Path: "<<endl;
    for(int i=0;i<dis.size();i++){
        if(dis[i] == INT_MAX) cout<<"INF"<<" ";
        else cout<<dis[i]<<" ";
    }
    cout<<endl;
}