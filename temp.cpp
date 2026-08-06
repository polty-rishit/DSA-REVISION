#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&ans,int node){
    set<pair<int,int>>s;
    s.insert({0,node});
    while(!s.empty()){
        auto [cost,node]=*s.begin();
        s.erase(s.begin());
        if(cost>ans[node])continue;
        for(auto i:adj[node]){
            int v=i.first,w=i.second;
            if(ans[node]+w<ans[v]){
                ans[v]=ans[node]+w;
                s.insert({ans[v],v});
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<pair<int,int>>>adj;
    unordered_map<int,vector<pair<int,int>>>rev;
    vector<vector<int>>nums;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        rev[v].push_back({u,w});
        nums.push_back({u,v,w});
    }
    vector<int>one(n+1,INT_MAX);
    one[1]=0;
    vector<int>two(n+1,INT_MAX);
    two[n]=0;
    bfs(adj,one,1);
    bfs(rev,two,n);
    int mini=INT_MAX;
    for(auto i:nums){
        int u=i[0],v=i[1],w=i[2];
        mini=min(mini,one[u]+w/2+two[v]);
    }
    cout<<mini<<endl;
}