#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findPar(int node){
        if(node==parent[node])return node;
        return parent[node]=findPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int ul_u=findPar(u);
        int ul_v=findPar(v);
        if(ul_u==ul_v)return;
        if(rank[ul_u]<rank[ul_v])parent[ul_u]=ul_v;
        else if(rank[ul_v]<rank[ul_u])parent[ul_v]=ul_u;
        else{
            parent[ul_v]=ul_u;
            rank[ul_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ul_u=findPar(u);
        int ul_v=findPar(v);
        if(ul_u==ul_v)return;
        if(size[ul_u]<size[ul_v]){
            parent[ul_u]=ul_v;
            size[ul_v]+=size[ul_u];
        }else{
            parent[ul_v]=ul_u;
            size[ul_u]+=size[ul_v];
        }
    }
};

int main(){
    //BY RANK
    // DisjointSet *ds=new DisjointSet(7);
    // ds->unionByRank(1,2);
    // ds->unionByRank(2,3);
    // ds->unionByRank(4,5);
    // ds->unionByRank(6,7);
    // ds->unionByRank(5,6);
    // if(ds->findPar(3)==ds->findPar(7))cout<<"same"<<endl;
    // else cout<<"not same"<<endl;
    // ds->unionByRank(3,7);
    // if(ds->findPar(3)==ds->findPar(7))cout<<"same"<<endl;
    // else cout<<"not same"<<endl;
    // return 0;
    
    //BY SIZE
    DisjointSet *ds=new DisjointSet(7);
    ds->unionBySize(1,2);
    ds->unionBySize(2,3);
    ds->unionBySize(4,5);
    ds->unionBySize(6,7);
    ds->unionBySize(5,6);
    if(ds->findPar(3)==ds->findPar(7))cout<<"same"<<endl;
    else cout<<"not same"<<endl;
    ds->unionBySize(3,7);
    if(ds->findPar(3)==ds->findPar(7))cout<<"same"<<endl;
    else cout<<"not same"<<endl;
    return 0;    
}