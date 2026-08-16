#include<bits/stdc++.h>
using namespace std;

int p(char a){
        if(a=='^')return 3;
        else if(a=='*' || a=='/')return 2;
        else if(a=='+' || a=='-')return 1;
        return -1;
}
void post(string &s,string &ans){
        int i=0;
        int n=s.size();
        stack<char>st;
        while(i<n){
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))ans+=s[i];
            else if(s[i]=='(')st.push(s[i]);
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if(!st.empty())st.pop();
            }else{
                while(!st.empty() && (p(s[i])<p(st.top()) || (p(s[i])==p(st.top()) && s[i]=='^'))){
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
    }

string infixToPrefix(string &s) {
        // code here
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')s[i]=')';
            else if(s[i]==')')s[i]='(';
        }
        string ans="";
        post(s,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }