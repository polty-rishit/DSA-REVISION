#include<bits/stdc++.h>
using namespace std;

vector<int>find(vector<int>&nums){
    vector<int>pre(nums.size(),0);
    pre[0]=nums[0];
    for(int i=1;i<nums.size();i++){
        pre[i]=max(pre[i-1],nums[i]);
    }
    return pre;
}

void print(vector<int>&nums){
    for(auto i:nums)cout<<i<<" ";
}
int main(){
    vector<int>nums={3,0,1,0,4,0,2};
    vector<int>ans=find(nums);
    print(ans);
}