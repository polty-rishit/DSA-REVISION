#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&nums,vector<vector<bool>>&vis,int i,int j,int newColor,int x){
    int n=nums.size(),m=nums[0].size();
    if(!vis[i][j]){
        vis[i][j]=1;
        nums[i][j]=newColor;
    }
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        auto [a,b]=q.front();
        q.pop();

        if(a+1<n && nums[a+1][b]==x && vis[a+1][b]==0){
            vis[a+1][b]=1;
            nums[a+1][b]=newColor;
            q.push({a+1,b});
        }
        if(a-1>=0 && nums[a-1][b]==x && vis[a-1][b]==0){
            vis[a-1][b]=1;
            nums[a-1][b]=newColor;
            q.push({a-1,b});
        }
        if(b+1<m && nums[a][b+1]==x && vis[a][b+1]==0){
            vis[a][b+1]=1;
            nums[a][b+1]=newColor;
            q.push({a,b+1});
        }
        if(b-1>=0 && nums[a][b-1]==x && vis[a][b-1]==0){
            vis[a][b-1]=1;
            nums[a][b-1]=newColor;
            q.push({a,b-1});
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>&nums,int newColor,int i,int j){
    if(nums[i][j]==newColor)return nums;
    int n=nums.size();
    int m=nums[0].size();

    vector<vector<bool>>vis(n,vector<bool>(m,0));
    dfs(nums,vis,i,j,newColor,nums[i][j]);
    return nums;
}