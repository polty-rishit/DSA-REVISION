#include<bits/stdc++.h>
using namespace std;

void dfs1(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node,stack<int>&s){
    if(!vis[node])vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            vis[i]=1;
            dfs1(adj,vis,i,s);
        }
    }
    s.push(node);
}

void dfs2(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node){
    if(!vis[node])vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            vis[i]=1;
            dfs2(adj,vis,i);
        }
    }
}

int numberOfStronglyConnectedComponents(vector<vector<int>>&nums,int V){
    unordered_map<int,vector<int>>adj;
    vector<bool>vis(V+1,0);
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
    }
    stack<int>s;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs1(adj,vis,i,s);
        }
    }
    unordered_map<int,vector<int>>rev;
    for(auto i:nums){
        int u=i[0],v=i[1];
        rev[v].push_back(u);
    }
    vector<bool>ans(V+1,0);
    int count=0;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!ans[node]){
            count++;
            dfs2(rev,ans,node);
        }
    }
    return count;
}

