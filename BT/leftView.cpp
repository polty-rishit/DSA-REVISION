#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        this->left=left;
        this->right=right;
    }
};

void left(Node *root,vector<int>&ans,int lvl){
        if(root==NULL)return;
        if(ans.size()==lvl)ans.push_back(root->data);
        left(root->left,ans,lvl+1);
        left(root->right,ans,lvl+1);
}

vector<int>leftView(Node *root){
    if(root==NULL)return {};
    vector<int>ans;
    left(root,ans,0);
    return ans;
}