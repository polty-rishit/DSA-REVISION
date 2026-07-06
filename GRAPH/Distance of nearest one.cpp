//Time complexity is : O(N*M)
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&nums,vector<vector<bool>>&vis,vector<vector<int>>&ans,queue<pair<pair<int,int>,int>>&q){
    int n=nums.size(),m=nums[0].size();
    while(!q.empty()){
        int i=q.front().first.first;
        int j=q.front().first.second;
        int step=q.front().second;
        q.pop();
        ans[i][j]=step;

        if(i+1<n && vis[i+1][j]==0){
            vis[i+1][j]=1;
            q.push({{i+1,j},step+1});
        }
        if(i-1>=0 && vis[i-1][j]==0){
            vis[i-1][j]=1;
            q.push({{i-1,j},step+1});
        }
        if(j+1<m && vis[i][j+1]==0){
            vis[i][j+1]==1;
            q.push({{i,j+1},step+1});
        }
        if(j-1>=0 && vis[i][j-1]==0){
            vis[i][j-1]==1;
            q.push({{i,j-1},step+1});
        }
    }
}

vector<vector<int>> nrearest(vector<vector<int>>&nums){
    int n=nums.size();
    int m=nums[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    vector<vector<int>>ans(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums[i][j]==1){
                vis[i][j]=1;
                q.push({{i,j},0});
            }
        }
    }
    bfs(nums,vis,ans,q);
    return ans;
}