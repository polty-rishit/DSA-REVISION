#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<char>>&nums,int i,int j,vector<vector<bool>>&vis){
    if(!vis[i][j])vis[i][j]=1;
    queue<pair<int,pair<int,int>>>q;
    int n=nums.size();
    q.push({0,{i,j}});
    while(!q.empty()){
        int dist=q.front().first;
        int i=q.front().second.first;
        int j=q.front().second.second;

        if(i==n-1 && j==n-1)return dist;

        if(i+1<0 && !vis[i+1][j] && nums[i+1][j]=='D'){
            vis[i+1][j]=1;
            q.push({dist+1,{i+1,j}});
        }
        if(i-1>=0 && !vis[i-1][j] && nums[i-1][j]=='D'){
            vis[i-1][j]=1;
            q.push({dist+1,{i-1,j}});
        }
        if(j+1<n && !vis[i][j+1] && nums[i][j+1]=='D'){
            vis[i][j+1]=1;
            q.push({dist+1,{i,j+1}});
        }
        if(j-1>=0 && !vis[i][j-1] && nums[i][j-1]=='D'){
            vis[i][j-1]=1;
            q.push({dist+1,{i,j-1}});
        }
    }
    return -1;
}

int minDis(vector<vector<char>>&nums){
    int n=nums.size();
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    int dist=bfs(nums,0,0,vis);
    return dist;
}
