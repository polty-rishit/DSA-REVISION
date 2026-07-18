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

void right(Node *root,vector<int>&ans,int lvl){
    if(root==NULL)return;
    if(lvl==ans.size())ans.push_back(root->data);
    right(root->right,ans,lvl+1);
    right(root->left,ans,lvl+1);
}

vector<int>rightView(Node *root){
    if(root==NULL)return {};
    vector<int>ans;
    right(root,ans,0);
    return ans;
}