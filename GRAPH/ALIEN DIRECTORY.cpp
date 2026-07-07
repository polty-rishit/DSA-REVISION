#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<char,vector<char>>&adj,queue<char>&q,unordered_map<char,int>&hsh,string &ans){
    while(!q.empty()){
        char a=q.front();
        q.pop();
        ans+=a;
        for(auto i:adj[a]){
            hsh[i]--;
            if(hsh[i]==0)q.push(i);
        }
    }
}

string alienDirectory(vector<string>&s){
    unordered_map<char,vector<char>>adj;
    unordered_map<char,int>hsh;
    for(auto i:s){
        for(auto c:i){
            hsh[c]+=0;
        }
    }
    for(int i=0;i+1<s.size();i++){
        string a=s[i];
        string b=s[i+1];
        int x=0,y=0;
        while(x<a.size() && y<b.size()){
            if(a[x]!=b[y]){
                if(find(adj[a[x]].begin(),adj[a[x]].end(),b[y])==adj[a[x]].end()){
                adj[a[x]].push_back(b[y]);
                hsh[b[y]]++;
            }
            break;
            }
            x++;
            y++;
        }
        if(x==a.size() || y==b.size()){
            if(a.size()>b.size() && y==b.size())return "";
        }
    }
    queue<char>q;
    for(auto i:hsh){
        if(i.second==0)q.push(i.first);
    }
    string ans="";
    bfs(adj,q,hsh,ans);
    if(ans.size()!=hsh.size())return "";
    return ans;
}


