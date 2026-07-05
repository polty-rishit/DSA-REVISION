//Time complexity of this is : O(N)+O(2M)
#include<bits/stdc++.h>
using namespace std;

vector<int>bfs(unordered_map<int,vector<int>>&adj,int n){
    vector<int>ans;
    vector<bool>vis(n+1,0);
    queue<int>q;
    vis[0]=1;
    q.push(0);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=true;
                q.push(i);
            }
        }
    }
    return ans;
}

int main(){
    unordered_map<int,vector<int>>adj;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans=bfs(adj,n);
}