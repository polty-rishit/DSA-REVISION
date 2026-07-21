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

int floor(Node* root,int key){
    int maxi=-1;
    while(root){
        if(root->data==key){
        maxi=root->data;
        return maxi;
    }
    if(key>root->data)root=root->right;
    else{
        maxi=root->data;
        root=root->left;
    }
}
    return maxi;
}