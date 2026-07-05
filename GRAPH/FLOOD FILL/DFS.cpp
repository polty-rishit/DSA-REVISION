#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&nums,int i,int j,int newColor,int x){
        int n=nums.size(),m=nums[0].size();
        if(nums[i][j]==x)nums[i][j]=newColor;
        
        if(i+1<n && nums[i+1][j]==x){
            nums[i+1][j]=newColor;
            dfs(nums,i+1,j,newColor,x);
        }
        if(i-1>=0 && nums[i-1][j]==x){
            nums[i-1][j]=newColor;
            dfs(nums,i-1,j,newColor,x);
        }
        if(j+1<m && nums[i][j+1]==x){
            nums[i][j+1]=newColor;
            dfs(nums,i,j+1,newColor,x);
        }
        if(j-1>=0 && nums[i][j-1]==x){
            nums[i][j-1]=newColor;
            dfs(nums,i,j-1,newColor,x);
        }
    }

vector<vector<int>> floodFill(vector<vector<int>>&nums, int i, int j,int newColor) {
        if(nums[i][j]==newColor)return nums;
        dfs(nums,i,j,newColor,nums[i][j]);
        return nums;
    }