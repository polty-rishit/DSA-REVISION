//Time complexity of this is O(N+2M)
#include<bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node,int parent){
    if(!vis[node])vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            vis[i]=1;
            if(dfs(adj,vis,i,node))return 1;
        }else if(i!=parent)return 1;
    }
    return 0;
}

bool isCycle(vector<vector<int>>&nums,int V){
    unordered_map<int,vector<int>>adj;
    vector<bool>vis(V+1,false);
    for(int i=0;i<nums.size();i++){
        int u=nums[i][0];
        int v=nums[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<V;i++)
    {
        if(!vis[i]){
            if(dfs(adj,vis,i,-1))return 1;
        }
    }
    return 0;
}