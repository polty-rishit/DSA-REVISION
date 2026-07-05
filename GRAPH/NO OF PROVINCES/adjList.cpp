//Time complexity : O(N)+O(N+2M) == roughly O(N)
#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node){
    if(!vis[node])vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            vis[i]=1;
            dfs(adj,vis,i);
        }
    }
}

int main(){
    unordered_map<int,vector<int>>adj;
    int n,m;
    cin>>n>>m;
    vector<bool>vis(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adj,vis,i);
            count++;
        }
    }
    cout<<count;
}