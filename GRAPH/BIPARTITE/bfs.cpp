#include<bits/stdc++.h>
using namespace std;

bool bfs(unordered_map<int,vector<int>>&adj,vector<int>&vis,int node){
    if(vis[node]==-1){
        vis[node]=0;
    }
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(vis[i]==-1){
                vis[i]=!vis[node];
                q.push(i);
            }else if(vis[i]==vis[node])return false;
        }
    }
    return true;
}

bool isBipartite(int V,vector<vector<int>>&nums){
    unordered_map<int,vector<int>>adj;
    vector<int>vis(V+1,-1);
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(bfs(adj,vis,0))return 1;
    return 0;
}
