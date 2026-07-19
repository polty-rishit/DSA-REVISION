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

    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        if(inorder.size()!=postorder.size())return NULL;
        map<int,int>hsh;
        for(int i=0;i<inorder.size();i++){
            hsh[inorder[i]]=i;
        }
        return buildTreePostIn(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hsh);
    }
    Node *buildTreePostIn(vector<int>&inorder,int inStart,int inEnd,vector<int>&postorder,int postStart,int postEnd,map<int,int>&hsh){
        if(postStart>postEnd || inStart>inEnd)return NULL;
        Node* root=new Node(postorder[postEnd]);
        int inRoot=hsh[postorder[postEnd]];
        int numsLeft=inRoot-inStart;
        root->left=buildTreePostIn(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsLeft-1,hsh);
        root->right=buildTreePostIn(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,hsh);
        return root;
    }