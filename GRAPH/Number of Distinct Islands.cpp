#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>&nums,vector<vector<bool>>&vis,int i,int j,vector<pair<int,int>>&v,int base0,int base1){
        if(!vis[i][j]){
            vis[i][j]=1;
            v.push_back({i-base0,j-base1});
        }
        int n=nums.size(),m=nums[0].size();
        
        if(i+1<n && nums[i+1][j]=='L' && vis[i+1][j]==0){
            vis[i+1][j]=1;
            v.push_back({i+1-base0,j-base1});
            dfs(nums,vis,i+1,j,v,base0,base1);
        }
        if(i-1>=0 && nums[i-1][j]=='L' && vis[i-1][j]==0){
            vis[i-1][j]=1;
            v.push_back({i-1-base0,j-base1});
            dfs(nums,vis,i-1,j,v,base0,base1);
        }
        if(j+1<m && nums[i][j+1]=='L' && vis[i][j+1]==0){
            vis[i][j+1]=1;
            v.push_back({i-base0,j+1-base1});
            dfs(nums,vis,i,j+1,v,base0,base1);
        }
        if(j-1>=0 && nums[i][j-1]=='L' && vis[i][j-1]==0){
            vis[i][j-1]=1;
            v.push_back({i-base0,j-1-base1});
            dfs(nums,vis,i,j-1,v,base0,base1);
        }
    }

    int countDistinctIslands(vector<vector<char>>&nums) {
        // code here
        int n=nums.size(),m=nums[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        set<vector<pair<int,int>>>s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && nums[i][j]=='L'){
                    vector<pair<int,int>>v;
                    dfs(nums,vis,i,j,v,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }