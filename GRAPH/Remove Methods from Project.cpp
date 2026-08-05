#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,vector<int>>&adj,vector<int>&vis,int node){
    if(!vis[node])vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            vis[i]=1;
            dfs(adj,vis,i);
        }
    }
}

void hfs(unordered_map<int,vector<int>>&adj,vector<int>&vis,int node,vector<int>&help){
    if(!help[node])help[node]=1;
    for(auto i:adj[node]){
        if(!help[i]){
            help[i]=1;
            if(vis[i])vis[i]=2;
            hfs(adj,vis,i,help);
        }
    }
}

vector<int>remainingMethods(int n,int k,vector<vector<int>>&nums){
    unordered_map<int,vector<int>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
    }
    vector<int>vis(n,0),help(n,0);
    dfs(adj,vis,k);
    for(int i=0;i<n;i++){
        if(i!=k && !help[i] && vis[i]==0){
            hfs(adj,vis,i,help);
        }
    }
    bool flag=0;
    for(int i=0;i<n;i++){
        if(vis[i]==2){
            flag=1;
            break;
        }
    }
    vector<int>fin;
    if(flag){
        for(int i=0;i<n;i++)fin.push_back(i);
    }else{
        for(int i=0;i<n;i++){
            if(vis[i]==0)fin.push_back(i);
        }
    }
    return fin;
}