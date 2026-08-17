#include<bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int>&nums) {
        // code here
        stack<int>s;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
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