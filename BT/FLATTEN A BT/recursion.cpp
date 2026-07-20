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
Node *previous=NULL;
void flatten(Node *root) {
        // code here
        if(root==NULL)return;
        flatten(root->right);
        flatten(root->left);
        root->right=previous;
        root->left=NULL;
        previous=root;
}