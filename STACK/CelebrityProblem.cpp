#include<bits/stdc++.h>
using namespace std;

int celebrityProblem(vector<vector<int>>&nums){
    int n=nums.size();
    int t=0;
    int end=n-1;
    while(t<end){
        if(nums[t][end]==1)t++;
        else if(nums[end][t]==1)end--;
        else{
            t++;
            end--;
        }
        if(t>end)return -1;
    }
    for(int i=0;i<n;i++){
        if(i==t)continue;
        if(nums[t][i]==0 && nums[i][end]==1)continue;
        else return -1;
    }
    return t;
}