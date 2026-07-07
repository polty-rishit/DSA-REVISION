#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&nums,vector<vector<int>>&ans,vector<int>&src,vector<int>&dest){
        int n=nums.size(),m=nums[0].size();
        set<pair<int,pair<int,int>>>s;
        int a=src[0],b=src[1];
        s.insert({0,{a,b}});
        while(!s.empty()){
            int dist=s.begin()->first;
            int i=s.begin()->second.first;
            int j=s.begin()->second.second;
            s.erase(s.begin());
            if(dist>ans[i][j])continue;
            if(i+1<n && nums[i+1][j]==1){
                if(1+dist<ans[i+1][j]){
                    ans[i+1][j]=1+dist;
                    s.insert({ans[i+1][j],{i+1,j}});
                }
            }
            if(i-1>=0 && nums[i-1][j]==1){
                if(1+dist<ans[i-1][j]){
                    ans[i-1][j]=1+dist;
                    s.insert({ans[i-1][j],{i-1,j}});
                }
            }
            if(j+1<m && nums[i][j+1]==1){
                if(1+dist<ans[i][j+1]){
                    ans[i][j+1]=1+dist;
                    s.insert({ans[i][j+1],{i,j+1}});
                }
            }
            if(j-1>=0 && nums[i][j-1]==1){
                if(1+dist<ans[i][j-1]){
                    ans[i][j-1]=1+dist;
                    s.insert({ans[i][j-1],{i,j-1}});
                }
            }
        }
}

int shortestPath(vector<vector<int>>&nums, vector<int> &src, vector<int> &dest) {
        // code here
        if(nums[src[0]][src[1]]==0 || nums[dest[0]][dest[1]]==0)return -1;
        vector<vector<int>>ans(nums.size(),vector<int>(nums[0].size(),INT_MAX));
        ans[src[0]][src[1]]=0;
        bfs(nums,ans,src,dest);
        if(ans[dest[0]][dest[1]]==INT_MAX)return -1;
        return ans[dest[0]][dest[1]];
}