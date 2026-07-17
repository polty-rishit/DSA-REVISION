#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data,Node *left,Node *right){
        this->data=data;
        this->left=left;
        this->right=right;
    }

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

vector<int>inOrder(Node *root){
    if(root==NULL)return {};
    vector<int>ans;
    stack<Node*>s;
    while(1){
        if(root!=NULL){
            s.push(root);
            root=root->left;
        }else{
            if(s.empty())break;
            root=s.top();
            s.pop();
            ans.push_back(root->data);
            root=root->right;
        }
    }
    return ans;
}