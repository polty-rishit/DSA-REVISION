#include<bits/stdc++.h>
using namespace std;

int p(char a){
    if(a=='^')return 3;
    else if(a=='*' || a=='/')return 2;
    else if(a=='+' || a=='-')return 1;
    return -1;
}
 
string infixToPost(string s){
    int i=0;
    int n=s.size();
    stack<char>st;
    string ans="";
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
            while(!st.empty() && (p(s[i])<p(st.top()) || (p(s[i])==p(st.top()) && s[i]!='^'))){
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
    return ans;
}