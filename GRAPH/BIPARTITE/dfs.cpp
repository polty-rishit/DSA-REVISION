#include<bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int,vector<int>>&adj,vector<int>&vis,int node){
        if(vis[node]==-1){
            vis[node]=0;
        }
        for(auto i:adj[node]){
            if(vis[i]==-1){
                vis[i]=!vis[node];
                if(!dfs(adj,vis,i))return false;
            }else if(vis[i]==vis[node])return false;
        }
        return 1;
    }

bool isBipartite(int V, vector<vector<int>> &nums) {
        // Code here
        unordered_map<int,vector<int>>adj;
        vector<int>vis(V,-1);
        for(auto i:nums){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(dfs(adj,vis,0))return 1;
        return 0;
    }