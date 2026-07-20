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

void flatten(Node* root){
    if(root==NULL)return;
    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node *node=s.top();
        s.pop();
        if(node->right)s.push(node->right);
        if(node->left)s.push(node->left);
        if(!s.empty())node->right=s.top();
        node->left=NULL;
    }
}