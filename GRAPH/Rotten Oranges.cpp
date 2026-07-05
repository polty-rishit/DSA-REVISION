//Time Complexity is O(N*M)
#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&nums,vector<vector<int>>&vis,int &t,queue<pair<pair<int,int>,int>>&q){
    int n=nums.size(),m=nums[0].size();
    while(!q.empty()){
        int i=q.front().first.first;
        int j=q.front().first.second;
        int time=q.front().second;
        q.pop();
        t=max(t,time);

        if(i+1<n && nums[i+1][j]==1 && vis[i+1][j]==0){
            vis[i+1][j]=2;
            nums[i+1][j]=2;
            q.push({{i+1,j},time+1});
        }
        if(i-1>=0 && nums[i-1][j]==1 && vis[i-1][j]==0){
            vis[i-1][j]=2;
            nums[i-1][j]=2;
            q.push({{i-1,j},time+1});
        }
        if(j+1<m && nums[i][j+1]==1 && vis[i][j+1]==0){
            vis[i][j+1]=2;
            nums[i][j+1]=2;
            q.push({{i,j+1},time+1});
        }
        if(j-1>=0 && nums[i][j-1]==1 && vis[i][j-1]==0){
            vis[i][j-1]=2;
            nums[i][j-1]=2;
            q.push({{i,j-1},time+1});
        }
    }
}

int timeTaken(vector<vector<int>>&nums){
    int n=nums.size(),m=nums[0].size();
    int t=0;
    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }
        }
    }
    bfs(nums,vis,t,q);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums[i][j]==1)return -1;
        }
    }
    return t;
}