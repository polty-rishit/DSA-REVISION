#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&ans,int node,vector<int>&parent){
    set<pair<int,int>>s;
    s.insert({0,node});
    while(!s.empty()){
        auto [dist,node]=*s.begin();
        s.erase(s.begin());
        if(dist>ans[node])continue;
        for(auto i:adj[node]){
            int n=i.first;
            int w=i.second;
            if(ans[node]+w<ans[n]){
                ans[n]=ans[node]+w;
                parent[n]=node;
                s.insert({ans[n],n});
            }
        }
    }
}

vector<int> shortestPath(vector<vector<int>>&nums,int n,int m){
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1],w=i[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>ans(n+1,INT_MAX);
    ans[1]=0;
    vector<int>parent(n+1,0);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    bfs(adj,ans,1,parent);
    if(ans[n]==INT_MAX)return {-1};
    int node=n;
    vector<int>fin;
    while(parent[node]!=node){
        fin.push_back(node);
        node=parent[node];
    }
    fin.push_back(node);
    reverse(fin.begin(),fin.end());
    fin.insert(fin.begin(),ans[n]);
    return fin;
}

