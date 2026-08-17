#include<bits/stdc++.h>
using namespace std;

int TrappingRainWater(vector<int>&nums){
    int n=nums.size();
    int leftMax=0,rightMax=0,l=0,r=n-1,t=0;
    while(l<r){
        if(nums[l]<=nums[r]){
            if(leftMax>nums[l])t+=(leftMax-nums[l]);
            else leftMax=nums[l];
            l++;
        }else{
            if(rightMax>nums[r])t+=(rightMax-nums[r]);
            else rightMax=nums[r];
            r--;
        }
    }
    return t;
}