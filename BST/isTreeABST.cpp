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

bool isValid(Node* root,long long maxi,long long mini){
    if(root==NULL)return 1;
    if(root->data>=maxi || root->data<=mini)return false;
    return isValid(root->left,root->data,mini)&& isValid(root->right,maxi,root->data);
}

bool isValidBst(Node* root){
    return isValid(root,INT_MAX,INT_MIN);
}