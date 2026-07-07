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


class Solution {
    private:
    void dfs(unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&vis,stack<int>&s,int node){
        if(!vis[node])vis[node]=1;
        for(auto i:adj[node]){
            int x=i.first;
            if(!vis[x]){
                vis[x]=1;
                dfs(adj,vis,s,x);
            }
        }
        s.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>&nums) {
        // code here
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<bool>vis(V+1,0);
        for(auto i:nums){
            int u=i[0],v=i[1],w=i[2];
            adj[u].push_back({v,w});
        }
        stack<int>s;
        vector<int>ans(V,INT_MAX);
        ans[0]=0;
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
};