//Time complexity of this is : O(N)+O(2M)
#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<int>&ans,int node){
    if(!vis[node])vis[node]=1;
    ans.push_back(node);
    for(auto i:adj[node]){
        if(!vis[i]){
            vis[i]=1;
            dfs(adj,vis,ans,i);
        }
    }
}

int main(){
    unordered_map<int,vector<int>>adj;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(n+1,0);
    vector<int>ans;
    int start=0;
    dfs(adj,vis,ans,start);
}