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

Node* in(Node* root,int &count,int k){
    if(root==NULL)return NULL;

    Node* left=in(root->left,count,k);
    if(left)return left;
    count++;
    if(count==k)return root;
    return in(root->right,count,k);
}

int KthSmalledtNode(Node* root,int k){
    int count=0;
    Node* node=in(root,count,k);
    if(node==NULL)return -1;
    return node->data;
}