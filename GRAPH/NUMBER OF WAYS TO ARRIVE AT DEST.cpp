#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&ans,vector<int>&ways,int node){
    set<pair<int,int>>s;
    s.insert({0,node});
    while(!s.empty()){
        auto [cost,node]=*s.begin();
        s.erase(s.begin());
        if(cost>ans[node])continue;
        for(auto i:adj[node]){
            int n=i.first,w=i.second;
            if(ans[node]+w<ans[n]){
                ans[n]=ans[node]+w;
                ways[n]=ways[node];
                s.insert({ans[n],n});
            }else if(ans[node]+w==ans[n])ways[n]+=ways[node];
        }
    }
}

int countPaths(int V,vector<vector<int>>&nums){
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1],w=i[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>ans(V,INT_MAX);
    vector<int>ways(V,0);
    ways[0]=1;
    ans[0]=0;
    bfs(adj,ans,ways,0);
    if(ways[V-1]==INT_MAX)return -1;
    return ways[V-1];
}