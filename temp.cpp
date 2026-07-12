#include<bits/stdc++.h>
using namespace std;

void print(vector<int>&temp){
    for(auto i:temp)cout<<i<<" ";
}

int find(int x,vector<int>&temp){
    for(int i=0;i<temp.size();i++){
        if(temp[i]==x)return i;
    }
    return -1;
}

int main(){
    vector<int>nums={37,12,28,9,100,56,80,5,12};
    vector<int>temp=nums;
    print(temp);
    cout<<endl;
    sort(temp.begin(),temp.end());
    print(temp);
    cout<<endl;
    vector<int>ans(nums.size(),-1);
    for(int i=0;i<nums.size();i++){
        int x=find(nums[i],temp);
        ans[i]=x+1;
    }
    print(ans);
}