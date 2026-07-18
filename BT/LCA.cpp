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

Node *lca(Node* root,Node *p,Node *q){
    if(root==NULL || p==root || q==root)return root;
    Node *left=lca(root->left,p,q);
    Node *right=lca(root->right,p,q);
    if(left==NULL)return right;
    if(right==NULL)return left;
    else return root;
}