#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    public:
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void lvl(Node *root,vector<int>&ans){
    if(root==NULL)return;

    queue<Node *>q;
    q.push(root);
    while (!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node *temp=q.front();
            q.pop();
            ans.push_back(temp->data);
            if(temp->left)q.push(root->left);
            if(temp->right)q.push(temp->right);
        }
    }
}

vector<int>levelOrder(Node* root){
    if(root==NULL)return {};
    vector<int>ans;
    lvl(root,ans);
    return ans;
}