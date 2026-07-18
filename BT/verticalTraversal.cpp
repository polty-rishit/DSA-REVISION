#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node *right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

vector<vector<int>> verticalView(Node *root){
    queue<pair<Node*,int>>q;
    map<int,vector<Node*>>hsh;
    q.push({root,0});
    vector<vector<int>>ans;
    while(!q.empty()){
        auto [node,line]=q.front();
        q.pop();
        hsh[line].push_back(node);
        if(node->left)q.push({node->left,line-1});
        if(node->right)q.push({node->right,line+1});
    }
    for(auto i:hsh){
        auto v=i.second;
        vector<int>temp;
        for(auto j:v){
            temp.push_back(j->data);
        }
        ans.push_back(temp);
    }
    return ans;
}