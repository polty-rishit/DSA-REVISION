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

int height(Node *root,int &maxi){
    if(root==NULL)return 0;
    int left=height(root->left,maxi);
    int right=height(root->right,maxi);
    maxi=max(maxi,left+right);
    return max(left,right)+1;
}
int diameter(Node *root){
    if(root==NULL)return 0;
    int maxi=0;
    height(root,maxi);
    return maxi;
}