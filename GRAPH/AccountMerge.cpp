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

vector<vector<string>> accMerge(vector<vector<string>>&nums) {
        // code here
        int n=nums.size();
        DisjointSet ds(n);
        unordered_map<string,int>hsh;
        for(int i=0;i<n;i++){
            for(int j=1;j<nums[i].size();j++){
                string mail=nums[i][j];
                if(hsh.find(mail)==hsh.end())hsh[mail]=i;
                else ds.unionBySize(i,hsh[mail]);
            }
        }
        vector<string>ans[n];
        for(auto i:hsh){
            string mail=i.first;
            int node=ds.findPar(i.second);
            ans[node].push_back(mail);
        }
        vector<vector<string>>fin;
        for(int i=0;i<n;i++){
            if(ans[i].size()==0)continue;
            sort(ans[i].begin(),ans[i].end());
            vector<string>temp;
            temp.push_back(nums[i][0]);
            for(auto x:ans[i])temp.push_back(x);
            fin.push_back(temp);
        }
        return fin;
}