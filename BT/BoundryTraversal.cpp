#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

bool isLeaf(Node *root){
        if(root->left==NULL && root->right==NULL)return true;
        return false;
    }
    void left(Node *root,vector<int>&ans){
        if(root==NULL)return ;
        Node *temp=root->left;
        while(temp){
            if(!isLeaf(temp))ans.push_back(temp->data);
            if(temp->left)temp=temp->left;
            else temp=temp->right;
        }
    }
    void right(Node *root,vector<int>&ans){
        if(root==NULL)return;
        Node *temp=root->right;
        vector<int>fin;
        while(temp){
            if(!isLeaf(temp))fin.push_back(temp->data);
            if(temp->right)temp=temp->right;
            else temp=temp->left;
        }
        reverse(fin.begin(),fin.end());
        ans.insert(ans.end(),fin.begin(),fin.end());
    }
    void leaf(Node *root,vector<int>&ans){
        if(!root)return;
        if(isLeaf(root)){
            ans.push_back(root->data);
            return ;
        }
        if(root->left)leaf(root->left,ans);
        if(root->right)leaf(root->right,ans);
}

vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(!isLeaf(root))ans.push_back(root->data);
        left(root,ans);
        leaf(root,ans);
        right(root,ans);
        return ans;
    }