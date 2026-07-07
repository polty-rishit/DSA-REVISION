#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&nums,vector<vector<int>>&ans,int a,int b){
        int n=nums.size(),m=nums[0].size();
        set<pair<int,pair<int,int>>>s;
        s.insert({0,{a,b}});
        while(!s.empty()){
            int dist=s.begin()->first;
            int i=s.begin()->second.first;
            int j=s.begin()->second.second;
            s.erase(s.begin());
            if(dist>ans[i][j])continue;
            if(i+1<n){
                int x=max(ans[i][j],abs(nums[i+1][j]-nums[i][j]));
                if(x<ans[i+1][j]){
                    ans[i+1][j]=x;
                    s.insert({ans[i+1][j],{i+1,j}});
                }
            }
            if(i-1>=0){
                int x=max(ans[i][j],abs(nums[i-1][j]-nums[i][j]));
                if(x<ans[i-1][j]){
                    ans[i-1][j]=x;
                    s.insert({ans[i-1][j],{i-1,j}});
                }
            }
            if(j+1<m){
                int x=max(ans[i][j],abs(nums[i][j+1]-nums[i][j]));
                if(x<ans[i][j+1]){
                    ans[i][j+1]=x;
                    s.insert({ans[i][j+1],{i,j+1}});
                }
            }
            if(j-1>=0){
                int x=max(ans[i][j],abs(nums[i][j-1]-nums[i][j]));
                if(x<ans[i][j-1]){
                    ans[i][j-1]=x;
                    s.insert({ans[i][j-1],{i,j-1}});
                }
            }
        }
    }

int minCostPath(vector<vector<int>>& nums) {
        // code here
        int n=nums.size(),m=nums[0].size();
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        ans[0][0]=0;
        bfs(nums,ans,0,0);
        return ans[n-1][m-1];
}