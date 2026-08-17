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
    long long small(vector<int>&nums){
        vector<int>nse=findNse(nums);
        vector<int>pse=findPse(nums);
        long long t=0;
        for(int i=0;i<nums.size();i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            t+=((long long)nums[i]*left*right);
        }
        return t;
    }
    vector<int>findNge(vector<int>&nums){
        stack<int>s;
        vector<int>ans(nums.size(),-1);
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&& nums[s.top()]<=nums[i])s.pop();
            ans[i]=s.empty()?n:s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int>findPge(vector<int>&nums){
        stack<int>s;
        int n=nums.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]<nums[i])s.pop();
            ans[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        return ans;
    }
    long long big(vector<int>&nums){
        vector<int>nge=findNge(nums);
        vector<int>pge=findPge(nums);
        long long t=0;
        for(int i=0;i<nums.size();i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;
            t+=((long long)nums[i]*left*right);
        }
        return t;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long mini=small(nums);
        long long maxi=big(nums);
        return (long long)((long long)maxi-(long long)mini);
    }