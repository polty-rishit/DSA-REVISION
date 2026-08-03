//dfs
#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node,vector<int>&temp){
    if(!vis[node])vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]){
            vis[i]=1;
            dfs(adj,vis,i,temp);
        }
    }
    temp.push_back(node);
}

vector<vector<int>>components(int V,vector<vector<int>>&nums){
    unordered_map<int,vector<int>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(V+1,0);
    vector<vector<int>>ans;
    for(int i=0;i<V;i++){
        vector<int>temp;
        if(!vis[i]){
            dfs(adj,vis,i,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}

//bfs
#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node,vector<int>&temp){
    if(!vis[node])vis[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        temp.push_back(node);
        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }
}

vector<vector<int>>components(int V,vector<vector<int>>&nums){
    unordered_map<int,vector<int>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(V+1,0);
    vector<vector<int>>ans;
    for(int i=0;i<V;i++){
        vector<int>temp;
        if(!vis[i]){
            bfs(adj,vis,i,temp);
            ans.push_back(temp);
        }
    }
    return ans;
}

