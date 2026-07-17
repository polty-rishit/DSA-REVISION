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

int maxDepth(Node *root){
    if(root==NULL)return 0;
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    return max(left,right)+1;
}