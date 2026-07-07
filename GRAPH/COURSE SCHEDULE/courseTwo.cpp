#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<int>>&adj,queue<int>&q,vector<int>&ans,vector<int>&in){
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto i:adj[node]){
            in[i]--;
            if(in[i]==0)q.push(i);
        }
    }
}

vector<int> course(vector<vector<int>>&nums,int V){
    unordered_map<int,vector<int>>adj;
    vector<int>in(V,0);
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[v].push_back(u);
        in[u]++;
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(in[i]==0)q.push(i);
    }
    vector<int>ans;
    bfs(adj,q,ans,in);
    if(ans.size()!=V)return {};
    return ans;
}