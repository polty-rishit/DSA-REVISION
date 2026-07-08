#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&ans,int node,int k){
    set<pair<int,pair<int,int>>>s;
    s.insert({0,{node,0}});
    while(!s.empty()){
        int stops=s.begin()->first;
        int node=s.begin()->second.first;
        int cost=s.begin()->second.second;
        s.erase(s.begin());
        if(stops>k)continue;
        for(auto i:adj[node]){
            int n=i.first,w=i.second;
            if(cost+w<ans[n] && stops<=k){
                ans[n]=cost+w;
                s.insert({stops+1,{n,ans[n]}});
            }
        }
    }
}

int cheapest(vector<vector<int>>&nums,int n,int src,int dest,int k){
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1],w=i[2];
        adj[u].push_back({v,w});
    }
    vector<int>ans(n,INT_MAX);
    ans[src]=0;
    bfs(adj,ans,src,k);
    if(ans[dest]==INT_MAX)return -1;
    return ans[dest];
}