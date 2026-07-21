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

Node *help(Node* root){
    if(root->left==NULL)return root->right;
    else if(root->right==NULL)return root->left;
    Node* rightChild=root->right;
    Node* lastRight=findLast(root->left);
    lastRight->right=rightChild;
    return root->left;
}

Node* findLast(Node *root){
    if(root->right==NULL)return root;
    return findLast(root->right);
}

Node* del(Node *root,int key){
    if(root==NULL)return NULL;
    if(root->data==key)return help(root);
    Node* node=root;
    while(root!=NULL){
        if(root->data>key){
            if(root->left && root->left->data==key){
                root->left=help(root->left);
                break;
            }else root=root->left;
        }else{
            if(root->right!=NULL && root->right->data==key){
                root->right=help(root->right);
                break;
            }else root=root->right;
        }
    }
    return node;
}