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

bool dfs(Node* root,vector<int>&ans,int x){
    if(!root)return false;
    ans.push_back(root->data);
    if(root->data==x)return 1;
    if(dfs(root->left,ans,x)||dfs(root->right,ans,x))return 1;
    ans.pop_back();
    return false; 
}

vector<int> rootToNode(Node* root,int x){
    vector<int>ans;
    if(root==NULL)return ans;
    dfs(root,ans,x);
    return ans;
}
