// //FLOYD WARSHAL
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>>nums(n+1,vector<long long>(n+1,LLONG_MAX));
    for(int i=1;i<=n;i++)nums[i][i]=0;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        nums[u][v]=w;
        nums[v][u]=w;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(nums[i][k]!=LLONG_MAX && nums[k][j]!=LLONG_MAX){
                    nums[i][j]=min(nums[i][j],nums[i][k]+nums[k][j]);
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        if(nums[u][v]==LLONG_MAX)cout<<-1<<endl;
        else cout<<nums[u][v]<<endl;;
    }
}

// //DIJKSTRA
// #include<bits/stdc++.h>
// using namespace std;

// void bfs(unordered_map<long long,vector<pair<long long,long long>>>&adj,vector<long long>&ans,long long node){
//     set<pair<long long,long long>>s;
//     s.insert({0,node});
//     while(!s.empty()){
//         auto [dist,node]=*s.begin();
//         s.erase(s.begin());
//         if(dist>ans[node])continue;
//         for(auto i:adj[node]){
//             long long n=i.first,w=i.second;
//             if(ans[node]+w<ans[n]){
//                 ans[n]=ans[node]+w;
//                 s.insert({ans[n],n});
//             }
//         }
//     }
// }

// void print(vector<long long>&ans){
//     for(auto i:ans)cout<<i<<endl;;
// }

// int main(){
//     long long n,m,q;
//     cin>>n>>m>>q;
//     unordered_map<long long,vector<pair<long long,long long>>>adj;
//     for(long long i=0;i<m;i++){
//         long long u,v,w;
//         cin>>u>>v>>w;
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }
//     vector<long long>fin;
//     for(long long i=0;i<q;i++){
//         long long src,dest;
//         cin>>src>>dest;
//         vector<long long>ans(n+1,LLONG_MAX);
//         ans[src]=0;
//         bfs(adj,ans,src);
//         if(ans[dest]==LLONG_MAX)fin.push_back(-1);
//         else fin.push_back(ans[dest]);
//     }
//     print(fin);
// }