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

void bfs(vector<vector<int>>&nums,vector<vector<bool>>&vis,int n,int m,int i,int j,int &count,DisjointSet &ds){
        if(i+1<n && vis[i+1][j]==1){
            int node=i*m+j;
            int adjNode=(i+1)*m+j;
            if(ds.findPar(node)!=ds.findPar(adjNode)){
                count--;
                ds.unionBySize(node,adjNode);
            }
        }
        if(i-1>=0 && vis[i-1][j]==1){
            int node=i*m+j;
            int adjNode=(i-1)*m+j;
            if(ds.findPar(node)!=ds.findPar(adjNode)){
                count--;
                ds.unionBySize(node,adjNode);
            }
        }
        if(j+1<m && vis[i][j+1]==1){
            int node=i*m+j;
            int adjNode=(i)*m+(j+1);
            if(ds.findPar(node)!=ds.findPar(adjNode)){
                count--;
                ds.unionBySize(node,adjNode);
            }
        }
        if(j-1>=0 && vis[i][j-1]==1){
            int node=i*m+j;
            int adjNode=(i)*m+(j-1);
            if(ds.findPar(node)!=ds.findPar(adjNode)){
                count--;
                ds.unionBySize(node,adjNode);
            }
        }
    }

vector<int>numOfIslands(vector<vector<int>>&nums,int n,int m){
    DisjointSet ds(n*m);
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    int count=0;
    vector<int>ans;
    for(auto x:nums){
        int i=x[0],j=x[1];
        if(vis[i][j]==1){
            ans.push_back(count);
            continue;
        }
        vis[i][j]=1;
        bfs(nums,vis,n,m,i,j,count,ds);
        ans.push_back(count);
    }
    return ans;
}