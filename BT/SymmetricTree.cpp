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

void preLeft(Node *root,vector<int>&ans){
    if(root==NULL){
        ans.push_back(INT_MIN);
        return;
    }
    ans.push_back(root->data);
    preLeft(root->left,ans);
    preLeft(root->right,ans);
}
    void preRight(Node* root,vector<int>&ans){
    if(root==NULL){
        ans.push_back(INT_MIN);
        return;
    }
    ans.push_back(root->data);
    preRight(root->right,ans);
    preRight(root->left,ans);
}

bool isSymmetric(Node* root) {
    Node* l=root->left;
    Node* r=root->right;
    vector<int>l1,r1;
    preLeft(l,l1);
    preRight(r,r1);
    return l1==r1;
}