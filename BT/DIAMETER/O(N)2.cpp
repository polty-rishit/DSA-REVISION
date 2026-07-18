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

int maxi=INT_MIN;

int height(Node *root){
    if(root==NULL)return 0;
    int left=height(root->left);
    int right=height(root->right);
    return 1+max(left,right);
}

int diameter(Node *root){
    if(root==NULL)return 0;
    int left=height(root->left);
    int right=height(root->right);
    maxi=max(maxi,left+right);

    diameter(root->left);
    diameter(root->right);
    return maxi;
}