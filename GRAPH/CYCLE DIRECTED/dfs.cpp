#include<bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<bool>&pathVis,int node){
    if(!vis[node]){
        vis[node]=1;
    }
        pathVis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=1;
                pathVis[i]=1;
                if(dfs(adj,vis,pathVis,i))return 1;
            }else if(vis[i] && pathVis[i])return 1;
        }
    pathVis[node]=0;
    return false;
}

bool isCyclic(vector<vector<int>>&nums,int V){
    unordered_map<int,vector<int>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
    }
    vector<bool>vis(V+1,0);
    vector<bool>pathVis(V+1,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(adj,vis,pathVis,i))return 1;
        }
    }
    return 0;
}