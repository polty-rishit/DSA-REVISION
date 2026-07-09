//FLOYD WARSHAL
#include<bits/stdc++.h>
using namespace std;

int findCity(vector<vector<int>>&nums,int k,int n,int m){
    vector<vector<int>>ans(n,vector<int>(n,INT_MAX));
    for(int i=0;i<n;i++)ans[i][i]=0;
    for(auto i:nums){
        int u=i[0],v=i[1],w=i[2];
        ans[u][v]=w;
        ans[v][u]=w;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ans[i][k]!=INT_MAX && ans[k][j]!=INT_MAX){
                    ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
                }
            }
        }
    }
    int maxi=INT_MAX;
    int city=-1;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(ans[i][j]<=k)count++;
        }
        if(count<=maxi){
            maxi=count;
            city=i;
        }
    }
    return city;
}


//DIJKSTRA
#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&ans,int node){
        set<pair<int,int>>s;
        s.insert({0,node});
        while(!s.empty()){
            auto [dist,node]=*s.begin();
            s.erase(s.begin());
            if(dist>ans[node])continue;
            for(auto i:adj[node]){
                int n=i.first,w=i.second;
                if(ans[node]+w<ans[n]){
                    ans[n]=ans[node]+w;
                    s.insert({ans[n],n});
                }
            }
        }
}

int findCity(int n, int m, vector<vector<int>>&nums, int k) {
        // Your code here
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto i:nums){
            int u=i[0],v=i[1],w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>fin(n,0);
        for(int i=0;i<n;i++){
            vector<int>ans(n,INT_MAX);
            ans[i]=0;
            bfs(adj,ans,i);
            int count=0;
            for(int j=0;j<n;j++){
                if(ans[j]<=k)count++;
            }
            fin[i]=count;
        }
        int temp=INT_MAX;
        int city=-1;
        for(int i=0;i<n;i++){
            if(fin[i]<=temp){
                temp=fin[i];
                city=i;
            }
        }
        return city;
}

