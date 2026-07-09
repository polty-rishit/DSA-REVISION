#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>&nums){
    int n=nums.size();
    for(int i=0;i<n;i++)nums[i][i]=0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i][k]!=INT_MAX && nums[k][j]!=INT_MAX){
                    nums[i][j]=min(nums[i][j],nums[i][k]+nums[k][j]);
                }
            }
        }
    }
}