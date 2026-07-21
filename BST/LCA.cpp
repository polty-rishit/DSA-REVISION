#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* LCA(Node *root,Node *p,Node* q){
    if(root==NULL)return NULL;
    int node=root->data;
    if(p->data>node && q->data>node)return LCA(root->right,p,q);
    if(p->data<node && q->data<node)return LCA(root->left,p,q);
    return root;
}