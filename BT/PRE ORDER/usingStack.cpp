// Firstly insert the right element then the left one as here we are using STACK and stack works on LIFO.
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

vector<int> preOrder(Node *root){
    if(root==NULL)return {};
    stack<Node*>s;
    s.push(root);
    vector<int>ans;
    while(!s.empty()){
        Node *temp=s.top();
        s.pop();
        ans.push_back(temp->data);
        if(temp->right)s.push(temp->right);
        if(temp->left)s.push(temp->left);
    }
    return ans;
}