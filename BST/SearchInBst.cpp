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

bool searchInBst(Node* root,int key){
    if(root==NULL)return false;
    while(root!=NULL && root->data!=key){
        if(root->data>key)root=root->left;
        else root=root->right;
    }
    return root;
}