#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int node){
    vis[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int a=q.front();
        q.pop();
        for(auto i:adj[a]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }
}
int main(){
    unordered_map<int,vector<int>>adj;
    int n,m;
    cin>>n>>m;
    vector<bool>vis(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(adj,vis,i);
            count++;
        }
    }
    cout<<count;
}