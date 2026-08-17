#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string s, int k) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(s[i]-'0')){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k){
            st.pop();
            k--;
        }
        if(st.empty())return "0";
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.empty())return "0";
        return ans;
}