//Time complexity of this is : O(N+2M)
#include<bits/stdc++.h>
using namespace std;

bool bfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node){
    if(!vis[node])vis[node]=1;
    queue<pair<int,int>>q;
    q.push({node,-1});
    while(!q.empty()){
        auto [node,parent]=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push({i,node});
            }else if(i!=parent)return 1;
        }
    }
    return 0;
}

bool isCycle(vector<vector<int>>&nums,int V)
{
    unordered_map<int,vector<int>>adj;
    vector<bool>vis(V+1,0);
    for(int i=0;i<nums.size();i++){
        int u=nums[i][0];
        int v=nums[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(bfs(adj,vis,i))return 1;
        }
    }
    return 0;
}