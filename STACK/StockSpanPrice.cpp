#include<bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(vector<int>&nums) {
        // code here
        stack<pair<int,int>>st;
        vector<int>ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && st.top().first<=nums[i])st.pop();
            int x=st.empty()?-1:st.top().second;
            ans[i]=i-x;
            st.push({nums[i],i});
        }
        return ans;
    }