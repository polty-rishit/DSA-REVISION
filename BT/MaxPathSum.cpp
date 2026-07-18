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

int sum(Node *root,int &maxi){
    if(root==NULL)return 0;
    int left=max(0,sum(root->left,maxi));
    int right=max(0,sum(root->right,maxi));
    maxi=max(maxi,root->data+left+right);
    return max(left,right)+root->data;
}

int maxPathSum(Node *root){
    int maxi=INT_MIN;
    sum(root,maxi);
    return maxi;
}