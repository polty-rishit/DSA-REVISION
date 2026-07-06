#include<bits/stdc++.h>
using namespace std;

void KahnAlgo(unordered_map<int,vector<int>>&adj,queue<int>&q,vector<int>&ans,vector<int>&in){
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

vector<int> topoSort(vector<vector<int>>&nums,int V){
    vector<int>in(V,0);
    unordered_map<int,vector<int>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1];
        adj[u].push_back(v);
        in[v]++;
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(in[i]==0)q.push(i);
    }
    vector<int>ans;
    KahnAlgo(adj,q,ans,in);
    return ans;
}