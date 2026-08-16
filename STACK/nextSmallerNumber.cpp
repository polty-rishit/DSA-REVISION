#include<bits/stdc++.h>
using namespace std;

vector<int>nextSmaller(vector<int>&nums){
    stack<int>s;
    vector<int>ans(nums.size(),-1);
    int n=nums.size();
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()>=nums[i])s.pop();
        ans[i]=s.empty()?-1:s.top();
        s.push(nums[i]);
    }
    return ans;
}