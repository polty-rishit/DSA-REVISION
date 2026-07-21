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

Node* suc(Node* root,int key){
        if(root==NULL)return NULL;
        Node* maxi=NULL;
        while(root){
            if(root->data==key){
                if(root->right){
                    root=root->right;
                    while(root->left)root=root->left;
                    return root;
                }
                return maxi;
            }
            if(key>=root->data)root=root->right;
            else{
                maxi=root;
                root=root->left;
            }
        }
        return maxi;
    }
    Node* pre(Node* root,int key){
        if(root==NULL)return NULL;
        Node* maxi=NULL;
        while(root){
            if(root->data==key){
                if(root->left){
                    root=root->left;
                    while(root->right)root=root->right;
                    return root;
                }
                return maxi;
            }
            if(key>=root->data){
                maxi=root;
                root=root->right;
            }else root=root->left;
        }
        return maxi;
    }
    
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*>ans;
        ans.push_back(pre(root,key));
        ans.push_back(suc(root,key));
        return ans;
    }