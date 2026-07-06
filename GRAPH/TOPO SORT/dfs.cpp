#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node,stack<int>&s){
    if(!vis[node])vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            vis[i]=1;
            dfs(adj,vis,i,s);
        }
    }
    s.push(node);
}

vector<int> topoSort(vector<vector<int>>&nums,int V){
    unordered_map<int,vector<int>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
    }
    vector<bool>vis(V,0);
    stack<int>s;
    for(int i=0;i<V;i++){
        if(!vis[i])dfs(adj,vis,i,s);
    }
    vector<int>ans;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        ans.push_back(node);
    }
    return ans;
}