#include<bits/stdc++.h>
using namespace std;

void prim(unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&vis,int node,vector<vector<int>>&ans){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>mini;
    mini.push({0,{node,-1}});
    while(!mini.empty()){
        int wt=mini.top().first;
        int node=mini.top().second.first;
        int parent=mini.top().second.second;
        mini.pop();
        if(vis[node])continue;
        vis[node]=1;
        ans.push_back({parent,node});
        for(auto i:adj[node]){
            int n=i.first,w=i.second;
            if(!vis[n])mini.push({w,{n,node}});
        }
    }
}

vector<vector<int>>minSpanTree(vector<vector<int>>&nums,int V){
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto i:nums){
        int u=i[0],v=i[1],w=i[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<int>vis(V+1,0);
    vector<vector<int>>ans;
    prim(adj,vis,0,ans);
    return ans;
}

void print(vector<vector<int>>&nums){
    for(auto i:nums){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>>nums={{0,1,5},{1,2,3},{0,2,1}};
    vector<vector<int>>ans=minSpanTree(nums,3);
    print(ans);
}