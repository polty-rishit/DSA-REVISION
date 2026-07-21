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

Node* insertInBst(Node* root,int key){
    if(root==NULL)return new Node(key);
    Node* node=root;
    while(1){
        if(key>=node->data){
            if(node->right)node=node->right;
            else{
                node->right=new Node(key);
                break;
            }
        }
        else{
            if(node->left)node=node->left;
            else{
                node->left=new Node(key);
                break;
            }
        }
    }
    return root;
}