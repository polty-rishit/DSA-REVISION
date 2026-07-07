#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<int>>&adj,queue<int>&q,int &count,vector<int>&in){
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        for(auto i:adj[node]){
            in[i]--;
            if(in[i]==0)q.push(i);
        }
    }
}

bool isCycle(vector<vector<int>>&nums,int V){
    unordered_map<int,vector<int>>adj;
    vector<int>in(V,0);
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
        in[v]++;
    }
    queue<int>q;
    int count=0;
    for(int i=0;i<V;i++){
        if(in[i]==0)q.push(i);
    }
    bfs(adj,q,count,in);
    if(count==V)return 0;
    return 1;
}