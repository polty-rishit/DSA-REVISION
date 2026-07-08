#include<bits/stdc++.h>
using namespace std;

int miniSteps(vector<int>&nums,int src,int end){
    if(src==end)return 0;
    const int MOD=1e3;
    src%=MOD,end%=MOD;
    queue<pair<int,int>>q;
    q.push({0,src});
    vector<int>ans(MOD,INT_MAX);
    while(!q.empty()){
        auto [steps,node]=q.front();
        q.pop();
        for(auto i:nums){
            int num=(node*i)%MOD;
            if(steps+1<ans[num]){
                ans[num]=steps+1;
                if(num==end)return ans[num];
                q.push({ans[num],num});
            }
        }
    }
    return -1;
}