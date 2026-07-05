#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>&nums,int i,int j){
    int n=nums.size(),m=nums[0].size();
    if(i>=n || i<0 || j>=m || j<0 || nums[i][j]=='0')return;
    nums[i][j]='0';
    dfs(nums,i+1,j);
    dfs(nums,i-1,j);
    dfs(nums,i,j+1);
    dfs(nums,i,j-1);
}

int numberOfIslands(vector<vector<char>>&nums){
    int count=0;
    int n=nums.size(),m=nums[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(nums[i][j]=='1'){
                dfs(nums,i,j);
                count++;
            }
        }
    }
    return count;
}