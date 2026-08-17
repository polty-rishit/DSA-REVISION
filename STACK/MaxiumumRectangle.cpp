#include<bits/stdc++.h>
using namespace std;
    int hist(vector<int>&nums){
        stack<int>s;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            while(!s.empty() && nums[s.top()]>nums[i]){
                int x=s.top();
                s.pop();
                int nse=i;
                int pse=s.empty()?-1:s.top();
                maxi=max(maxi,nums[x]*(nse-pse-1));
            }
            s.push(i);
        }
        while(!s.empty()){
            int nse=n;
            int x=s.top();
            s.pop();
            int pse=s.empty()?-1:s.top();
            maxi=max(maxi,nums[x]*(nse-pse-1));
        }
        return maxi;
    }

    int maxArea(vector<vector<int>>&nums) {
        // code here
        int n=nums.size(),m=nums[0].size();
        int maxi=INT_MIN;
        vector<vector<int>>pre(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i][j];
                if(nums[i][j]==0)sum=0;
                pre[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,hist(pre[i]));
        }
        return maxi;
    }