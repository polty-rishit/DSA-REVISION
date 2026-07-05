//The input of nums is like nums=[[1,1,0],[1,1,0],[0,0,1]]
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
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums.size();j++){
            if(nums[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int count=0;
    vector<bool>vis(nums.size()+1,0);
    for(int i=0;i<nums.size();i++){
        if(vis[i]==0){
            dfs(adj,vis,i);
            count++;
        }
    }
    cout<<count;
}