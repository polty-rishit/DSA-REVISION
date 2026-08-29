  #include<bits/stdc++.h>
using namespace std;

int main(){
    string s="(A+B)*C-D+F";
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')s[i]=')';
        else if(s[i]==')')s[i]='(';
    }
    cout<<s<<endl;
}
