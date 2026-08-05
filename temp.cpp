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
                int v=i.first,w=i.second;
                if(ans[node]+w<ans[v]){
                    ans[v]=ans[node]+v;
                    s.insert({ans[v],v});
                }
            }
        }
    }

vector<int> findDelayTime(int V, vector<vector<int>>&nums, int src) {
        // code here
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto i:nums){
            int u=i[0],v=i[1],w=i[2];
            adj[u].push_back({v,w});
        }
        vector<int>ans(V,INT_MAX);
        ans[src]=0;
        bfs(adj,ans,src);
        for(int i=0;i<V;i++){
            if(ans[i]==INT_MAX)ans[i]=-1;
        }
        return ans;
    }

void print(vector<int>&ans){
    for(auto i:ans){
        cout<<i<<" ";
    }
}

int main(){
    vector<vector<int>>nums={{0,1,2},{2,1,2},{0,1,4}};
    int V=3;
    int src=0;
    vector<int>ans=findDelayTime(V,nums,src);
    print(ans);
}