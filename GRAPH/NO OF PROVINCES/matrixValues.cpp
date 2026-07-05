// The input of nums is like nums=[[0, 1], [2, 1], [3, 4]] and v=5
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
    vector<vector<int>>nums;
    unordered_map<int,vector<int>>adj;
    int n;
    cin>>n;
    for(auto i:nums){
        int u=i[0];
        int v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count=0;
    vector<bool>vis(n+1,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adj,vis,i);
            count++;
        }
    }
    cout<<count<<endl;
}