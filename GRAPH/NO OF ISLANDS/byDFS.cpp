#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>&nums,vector<vector<bool>>&vis,int i,int j){
    int n=nums.size(),m=nums[0].size();
    if(!vis[i][j])vis[i][j]=1;
    
        if(i+1<n && nums[i+1][j]=='1' && vis[i+1][j]==0){
            vis[i+1][j]=1;
            dfs(nums,vis,i+1,j);
        }
        if(i-1>=0 && nums[i-1][j]=='1' && vis[i-1][j]==0){
            vis[i-1][j]=1;
            dfs(nums,vis,i-1,j);
        }
        if(j+1<m && nums[i][j+1]=='1' && vis[i][j+1]==0){
            vis[i][j+1]=1;
            dfs(nums,vis,i,j+1);
        }
        if(j-1>=0 && nums[i][j-1]=='1' && vis[i][j-1]==0){
            vis[i][j-1]=1;
            dfs(nums,vis,i,j-1);
        }
}

int isLands(vector<vector<char>>&nums){
    int n=nums.size();
    int m=nums[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && nums[i][j]=='1'){
                dfs(nums,vis,i,j);
                count++;
            }
        }
    }
    return count;
}