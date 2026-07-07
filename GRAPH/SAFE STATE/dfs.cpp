#include<bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<bool>&pathVis,vector<bool>&ans,int node){
    if(!vis[node]){
        vis[node]=1;
        pathVis[node]=1;
        ans[node]=0;
    }
    for(auto i:adj[node]){
        if(!vis[i]){
            vis[i]=1;
            pathVis[i]=1;
            if(dfs(adj,vis,pathVis,ans,i)){
                ans[i]=0;
                return 1;
            }
        }else if(vis[i] && pathVis[i]){
            ans[i]=0;
            return 1;
        }
    }
    ans[node]=1;
    pathVis[node]=0;
    return 0;
}

vector<int> safeState(vector<vector<int>>&nums,int V){
    unordered_map<int,vector<int>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
    }
    vector<bool>vis(V,0),pathVis(V,0),ans(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i])dfs(adj,vis,pathVis,ans,i);
    }
    vector<int>fin;
    for(int i=0;i<V;i++){
        if(ans[i]==1)fin.push_back(i);
    }
    return fin;
}