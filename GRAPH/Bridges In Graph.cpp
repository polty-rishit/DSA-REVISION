#include<bits/stdc++.h>
using namespace std;

int timer=1;

void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<vector<int>>&ans,int node,int parent,vector<int>&tin,vector<int>&low){
        if(!vis[node])vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto i:adj[node]){
            if(i==parent)continue;
            if(!vis[i]){
                dfs(adj,vis,ans,i,node,tin,low);
                low[node]=min(low[node],low[i]);
                if(low[i]>tin[node]){
                    ans.push_back({i,node});
                }
            }else low[node]=min(low[node],low[i]);
        }
}

vector<vector<int>> criticalConnections(int V, vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>adj;
        for(auto i:nums){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool>vis(V+1,0);
        vector<vector<int>>ans;
        vector<int>tin(V+1,0);
        vector<int>low(V+1,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,vis,ans,i,-1,tin,low);
            }
        }
        return ans;
}