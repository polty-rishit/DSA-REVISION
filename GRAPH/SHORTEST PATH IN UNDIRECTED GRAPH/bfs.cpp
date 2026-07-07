#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<int>&ans,int node){
    if(!vis[node])vis[node]=1;
    queue<pair<int,int>>q;
    q.push({node,0});
    while(!q.empty()){
        auto [node,dist]=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=1;
                if(ans[node]!=INT_MAX)ans[i]=min(ans[i],ans[node]+1);
                q.push({i,dist+1});
            }
        }
    }
}

int shortestDist(int V,vector<vector<int>>&nums,int src,int dest){
    unordered_map<int,vector<int>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(V+1,0);
    vector<int>ans(V,INT_MAX);
    ans[src]=0;
    bfs(adj,vis,ans,src);
    for(int i=0;i<V;i++){
        if(ans[i]==INT_MAX)ans[i]=-1;
    }
    return ans[dest];
}



//ALSO WE CAN DO AS 
#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,vector<int>&ans,int node){
    if(!vis[node])vis[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(!vis[i]){
            vis[i]=1;
            ans[i]=min(ans[node]+1,ans[i]);
            q.push(i);
            }
        }
    }
}

int shortestPath(int V, vector<vector<int>> &nums, int src, int dest) {
    unordered_map<int,vector<int>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>vis(V+1,0);
    vector<int>ans(V,INT_MAX);
    ans[src]=0;
    bfs(adj,vis,ans,src);
    for(int i=0;i<V;i++){
        if(ans[i]==INT_MAX)ans[i]=-1;
    }
    return ans[dest];
}