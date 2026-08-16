#include<bits/stdc++.h>
using namespace std;

vector<int>nextGreater(vector<int>&nums){
    stack<int>s;
    vector<int>ans(nums.size(),-1);
    for(int i=nums.size()-1;i>=0;i--){
        while(!s.empty() && s.top()<=nums[i])s.pop();
        if(s.empty())ans[i]=-1;
        else ans[i]=s.top();
        s.push(nums[i]);
    }
    return ans;
}

void print(vector<int>&nums){
    for(auto i:nums)cout<<i<<" ";
}

int main(){
    vector<int>nums={1, 3, 2, 4};
    vector<int>ans=nextGreater(nums);
    print(ans);
}