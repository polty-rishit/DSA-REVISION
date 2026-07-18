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

void pre(Node *root,vector<int>&ans){
    if(root==NULL)return;
    ans.push_back(root->data);
    pre(root->left,ans);
    pre(root->right,ans);
}

bool isTreeIdentical(Node *r1,Node *r2){
    vector<int>pre1,pre2;
    pre(r1,pre1);
    pre(r2,pre2);
    return pre1==pre2;
}