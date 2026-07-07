#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&ans,int node){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
    mini.push({0,node});
    while(!mini.empty()){
        auto [dist,node]=mini.top();
        mini.pop();
        if(dist>ans[node])continue;
        for(auto i:adj[node]){
            int n=i.first;
            int w=i.second;
            if(ans[node]+w<ans[n]){
                ans[n]=ans[node]+w;
                mini.push({ans[n],n});
            }
        }
    }
}

vector<int> shortestDistance(vector<vector<int>>&nums,int V,int src){
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1],w=i[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>ans(V,INT_MAX);
    ans[src]=0;
    bfs(adj,ans,src);
    for(int i=0;i<V;i++){
        if(ans[i]==INT_MAX)ans[i]=-1;
    }
    return ans;
}