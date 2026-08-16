#include<bits/stdc++.h>
using namespace std;

    string postToInfix(string &s) {
        // Write your code here
        int i=0;
        int n=s.size();
        stack<string>st;
        while(i<n){
            if((s[i]>='A' && s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))st.push(string(1,s[i]));
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string c="("+t2+s[i]+t1+")";
                st.push(c);
            }
            i++;
        }
        return st.top();
    }