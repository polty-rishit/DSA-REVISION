#include<bits/stdc++.h>
using namespace std;

void prim(unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&vis,int node,int &sum){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
    mini.push({0,node});
    while(!mini.empty()){
        auto [wt,node]=mini.top();
        mini.pop();
        if(vis[node])continue;
        vis[node]=1;
        sum+=wt;
        for(auto i:adj[node]){
            int n=i.first,w=i.second;
            if(!vis[n])mini.push({w,n});
        }
    }
}

int sumOfMinimumSpannngTree(vector<vector<int>>&nums,int V){
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1],w=i[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int sum=0;
    vector<int>vis(V+1,0);
    prim(adj,vis,0,sum);
    return sum;
}