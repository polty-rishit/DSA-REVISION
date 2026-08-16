#include<bits/stdc++.h>
using namespace std;

    string postToPre(string s) {
        // code here
        stack<string>st;
        int i=0;
        int n=s.size();
        while(i<n){
            if((s[i]>='A' && s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))st.push(string(1,s[i]));
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string c=s[i]+t2+t1;
                st.push(c);
            }
            i++;
        }
        return st.top();
    }