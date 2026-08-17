#include<bits/stdc++.h>
using namespace std;

vector<int>findNse(vector<int>&nums){
    stack<int>s;
    vector<int>ans(nums.size(),-1);
    int n=nums.size();
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && nums[s.top()]>=nums[i])s.pop();
        ans[i]=s.empty()?n:s.top();
        s.push(i);
    }
    return ans;
}
vector<int>findPse(vector<int>&nums){
    stack<int>s;
    vector<int>ans(nums.size(),-1);
    int n=nums.size();
    for(int i=0;i<n;i++){
        while(!s.empty() && nums[s.top()]>nums[i])s.pop();
        ans[i]=s.empty()?-1:s.top();
        s.push(i);
    }
    return ans;
}

int sumofsubarrayMinimums(vector<int>&nums){
    vector<int>nse=findNse(nums);
    vector<int>pse=findPse(nums);
    int t=0;
    for(int i=0;i<nums.size();i++){
        int left=i-pse[i];
        int right=nse[i]-i;
        t+=(nums[i]*left*right);
    }
    return t;
}