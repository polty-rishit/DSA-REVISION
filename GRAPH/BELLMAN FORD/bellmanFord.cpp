#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>&nums,int V,int src){
    vector<int>ans(V,INT_MAX);
    ans[src]=0;
    for(int i=0;i<V-1;i++){
        for(auto i:nums){
            int u=i[0],v=i[1],w=i[2];
            if(ans[u]!=INT_MAX && ans[u]+w<ans[v])ans[v]=ans[u]+w;
        }
    }
    //If negative cycle is there in the graph then the loop will run for the Nth time also, 
    //but if there is no negative cycle then the loop only run for n-1 times.
    //and this loop will be skiped and the originl ans array that has the original shortest weights will be returned.
    for(auto i:nums){
        int u=i[0],v=i[1],w=i[2];
        if(ans[u]!=INT_MAX && ans[u]+w<ans[v])return {-1};
    }
    return ans;
}