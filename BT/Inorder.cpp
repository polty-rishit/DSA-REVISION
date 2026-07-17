//LEFT -> ROOT -> RIGHT
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

void in(Node *root,vector<int>&ans){
    if(root==NULL)return;
    in(root->left,ans);
    ans.push_back(root->data);
    in(root->right,ans);
}

vector<int> Inorder(Node *root){
    vector<int>ans;
    in(root,ans);
    return ans;
}