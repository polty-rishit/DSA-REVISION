#include<bits/stdc++.h>
using namespace std;

    string preToPost(string &s) {
        // code here
        stack<string>st;
        int i=s.size()-1;
        int n=s.size();
        while(i>=0){
            if((s[i]>='A' && s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))st.push(string(1,s[i]));
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string c=t1+t2+s[i];
                st.push(c);
            }
            i--;
        }
        return st.top();
    }