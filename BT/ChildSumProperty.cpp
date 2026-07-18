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

void childSumProperty(Node *root){
    if(root==NULL)return;
    int child=0;
    if(root->left)child+=root->left->data;
    if(root->right)child+=root->right->data;
    if(child>=root->data)root->data=child;
    else{
        if(root->left)root->left->data=root->data;
        else if(root->right)root->right->data=root->data;
    }
        childSumProperty(root->left);
        childSumProperty(root->right);
        int t=0;
        if(root->left)t+=root->left->data;
        if(root->right)t+=root->right->data;
        if(root->left || root->right)root->data=t;
}