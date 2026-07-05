#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>&nums,vector<vector<bool>>&vis,int i,int j){
        vis[i][j]=1;
        int n=nums.size();
        int m=nums[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();
            if(a+1<n && nums[a+1][b]=='1' && !vis[a+1][b]){
                vis[a+1][b]=1;
                q.push({a+1,b});
            }
            if(a-1>=0 && nums[a-1][b]=='1' && !vis[a-1][b]){
                vis[a-1][b]=1;
                q.push({a-1,b});
            }
            if(b+1<m && nums[a][b+1]=='1' && !vis[a][b+1]){
                vis[a][b+1]=1;
                q.push({a,b+1});
            }
            if(b-1>=0 && nums[a][b-1]=='1' && !vis[a][b-1]){
                vis[a][b-1]=1;
                q.push({a,b-1});
            }
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
                bfs(nums,vis,i,j);
                count++;
            }
        }
    }
    return count;
}