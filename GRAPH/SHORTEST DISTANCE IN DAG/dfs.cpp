#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&vis,stack<int>&s,int node){
    if(!vis[node])vis[node]=1;
    for(auto i:adj[node]){
        int v=i.first;
        if(!vis[v]){
            vis[v]=1;
            dfs(adj,vis,s,v);
        }
    }
    s.push(node);
}

vector<int> shortestPath(vector<vector<int>>&nums,int V,int E){
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1],w=i[2];
        adj[u].push_back({v,w});
    }
    vector<bool>vis(V,0);
    vector<int>ans(V,INT_MAX);
    ans[0]=0;
    stack<int>s;
    for(int i=0;i<V;i++){
        if(!vis[i])dfs(adj,vis,s,i);
    }
    while(!s.empty()){
        int node=s.top();
        s.pop();
        for(auto i:adj[node]){
            int a=i.first,b=i.second;
            if(ans[node]!=INT_MAX)ans[a]=min(ans[a],ans[node]+b);
        }
    }
    for(int i=0;i<V;i++){
        if(ans[i]==INT_MAX)ans[i]=-1;
    }
    return ans;
}


