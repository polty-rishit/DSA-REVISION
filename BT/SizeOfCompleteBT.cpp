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

int findLeft(Node* root){
        if(root==NULL)return 0;
        int h=0;
        while(root){
            h++;
            root=root->left;
        }
        return h;
    }
    int findRight(Node *root){
        if(root==NULL)return 0;
        int h=0;
        while(root){
            h++;
            root=root->right;
        }
        return h;
    }

int countNodes(Node* root) {
        // code here
        if(root==NULL)return 0;
        int left=findLeft(root);
        int right=findRight(root);
        if(left==right)return (int)pow(2,left)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }