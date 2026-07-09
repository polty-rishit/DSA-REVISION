#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
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

void bfs(vector<vector<int>>&nums,DisjointSet &ds,int i,int j){
        int n=nums.size();
        if(i+1<n && nums[i+1][j]==1){
            int node=i*n+j;
            int newNode=(i+1)*n+j;
            ds.unionBySize(node,newNode);
        }
        if(i-1>=0 && nums[i-1][j]==1){
            int node=i*n+j;
            int newNode=(i-1)*n+j;
            ds.unionBySize(node,newNode);
        }
        if(j+1<n && nums[i][j+1]==1){
            int node=i*n+j;
            int newNode=(i)*n+(j+1);
            ds.unionBySize(node,newNode);
        }
        if(j-1>=0 && nums[i][j-1]==1){
            int node=i*n+j;
            int newNode=(i)*n+(j-1);
            ds.unionBySize(node,newNode);
        }
    }
    void dsu(vector<vector<int>>&nums,set<int>&s,int i,int j,DisjointSet &ds){
        int n=nums.size();
        if(i+1<n && nums[i+1][j]==1)s.insert(ds.findPar((i+1)*n+j));
        if(i-1>=0 && nums[i-1][j]==1)s.insert(ds.findPar((i-1)*n+j));
        if(j+1<n && nums[i][j+1]==1)s.insert(ds.findPar((i)*n+(j+1)));
        if(j-1>=0 && nums[i][j-1]==1)s.insert(ds.findPar((i)*n+(j-1)));
    }

int largestIsland(vector<vector<int>>&nums) {
        // Your code goes here.
        int n=nums.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j]==0)continue;
                bfs(nums,ds,i,j);
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i][j]==1)continue;
                set<int>s;
                dsu(nums,s,i,j,ds);
                int sizeTotal=0;
                for(auto x:s){
                    sizeTotal+=ds.size[x];
                }
                mx=max(mx,sizeTotal+1);
            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findPar(i)]);
        }
        return mx;
    }