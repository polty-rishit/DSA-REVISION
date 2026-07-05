//UnDirected Graph using Matrix
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    int adj[n][m];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
}

//Undirected Graph using List
#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,vector<int>>adj;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

//Directed Graph using List
#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,vector<int>>adj;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
}

//Graph with weights
#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,vector<pair<int,int>>>adj;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
}