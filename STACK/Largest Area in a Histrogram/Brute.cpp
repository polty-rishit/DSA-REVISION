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

    int getMaxArea(vector<int>&nums) {
        // code here
        vector<int>pse=findPse(nums);
        vector<int>nse=findNse(nums);
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
