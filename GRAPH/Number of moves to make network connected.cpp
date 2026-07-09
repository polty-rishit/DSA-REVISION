#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findPar(int node){
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ul_u=findPar(u);
        int ul_v=findPar(v);
        if(ul_u==ul_v)return;
        if(rank[ul_u]<rank[ul_v])parent[ul_u]=ul_v;
        else if(rank[ul_v]<rank[ul_u])parent[ul_v]=ul_u;
        else{
            parent[ul_v]=ul_u;
            rank[ul_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ul_u=findPar(u);
        int ul_v=findPar(v);
        if(ul_u==ul_v)return;
        if(size[ul_u]<size[ul_v]){
            parent[ul_u]=ul_v;
            size[ul_v]+=size[ul_u];
        }else{
            parent[ul_v]=ul_u;
            size[ul_u]+=size[ul_v];
        }
    }
};

int numberOfOperation(vector<vector<int>>&nums,int V){
    DisjointSet ds(V);
    for(auto i:nums){
        int u=i[0],v=i[1];
        ds.unionByRank(u,v);
    }
    unordered_map<int,int>hsh;
    for(int i=0;i<V;i++){
        int x=ds.findPar(i);
        hsh[x]++;
    }
    if(nums.size()<V-1)return -1;
    return hsh.size()-1;
}