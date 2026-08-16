#include<bits/stdc++.h>
using namespace std;

int tappingrainWater(vector<int>&nums){
    int n=nums.size();
    vector<int>pre(n,0);
    vector<int>suf(n,0);
    pre[0]=nums[0];
    suf[n-1]=nums[n-1];
    for(int i=1;i<n;i++)pre[i]=max(pre[i-1],nums[i]);
    for(int i=n-2;i>=0;i--)suf[i]=max(pre[i+1],nums[i]);
    int t=0;
    for(int i=0;i<n;i++){
        int maxi=min(pre[i],suf[i]);
        if(maxi>nums[i])t+=maxi-nums[i];
    }
    return t;
}