#include<bits/stdc++.h>
using namespace std;

vector<int>nextGreaterElement(vector<int>&nums){
    stack<int>s;
    int n=nums.size();
    vector<int>ans(n,-1);
    for(int i=2*n-1;i>=0;i--){
        while(!s.empty() && s.top()<=nums[i%n])s.pop();
        if(i<n)ans[i]=s.empty()?-1:s.top();
        s.push(nums[i%n]);
    }
    return ans;
}