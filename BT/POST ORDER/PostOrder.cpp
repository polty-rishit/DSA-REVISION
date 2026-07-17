// LEFT -> RIGHT -> ROOT
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

void post(Node *root,vector<int>&ans){
    if(root==NULL)return;
    post(root->left,ans);
    post(root->right,ans);
    ans.push_back(root->data);
}

vector<int> postOrder(Node *root){
    vector<int>ans;
    post(root,ans);
    return ans;
}
