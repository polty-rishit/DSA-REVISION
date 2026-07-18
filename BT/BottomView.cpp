#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

vector<int>bottomView(Node *root){
    if(root==NULL)return {};
    queue<pair<Node *,int>>q;
    vector<int>ans;
    q.push({root,0});
    map<int,Node*>hsh;
    while(!q.empty()){
        auto [node,line]=q.front();
        q.pop();
        hsh[line]=node;
        if(node->left)q.push({node->left,line-1});
        if(node->right)q.push({node->right,line+1});
    }
    for(auto &p:hsh){
        ans.push_back(p.second->data);
    }
    return ans;
}