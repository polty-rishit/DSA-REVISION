//ROOT-> LEFT -> RIGHT
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data,Node *left,Node *right){
        this->data=data;
        this->left=left;
        this->right=right;
    }

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void pre(Node *root,vector<int>&ans){
    if(root==NULL)return;
    ans.push_back(root->data);
    pre(root->left,ans);
    pre(root->right,ans);
}

vector<int>preOrder(Node *root){
    vector<int>ans;
    pre(root,ans);
    return ans;
}