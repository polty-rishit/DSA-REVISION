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

void number(Node* root,int &count){
        if(root==NULL)return ;
        count++;
        number(root->left,count);
        number(root->right,count);
    }
    Node* in(Node* root,int &count,int k){
        if(root==NULL)return NULL;
        
        Node* left=in(root->left,count,k);
        if(left)return left;
        count++;
        if(count==k)return root;
        return in(root->right,count,k);
    }
    
    int kthLargest(Node *root, int k) {
        // code here
        int count=0;
        number(root,count);
        int key=count-k+1;
        int ans=0;
        Node* temp=in(root,ans,key);
        if(temp==NULL)return -1;
        return temp->data;
    }