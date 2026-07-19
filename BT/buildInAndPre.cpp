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

Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        map<int,int>hsh;
        for(int i=0;i<inorder.size();i++){
            hsh[inorder[i]]=i;
        }
        Node* root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,hsh);
        return root;
    }
    
Node* buildTree(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&hsh){
        if(preStart>preEnd || inStart>inEnd)return NULL;
        Node* root=new Node(preorder[preStart]);
        int inRoot=hsh[root->data];
        int numsLeft=inRoot-inStart;
        root->left=buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,hsh);
        root->right=buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,hsh);
        return root;
    }