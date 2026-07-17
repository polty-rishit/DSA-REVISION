#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    public:
    Node(int data){
        this->data=data;
        this->left=left;
        this->right=right;
    }
};

vector<int>postOrder(Node *root){
    if(root==NULL)return {};
    stack<Node *>s1,s2;
    s1.push(root);
    vector<int>ans;
    while(!s1.empty()){
        Node *temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)s1.push(temp->left);
        if(temp->right)s1.push(temp->right);
    }
    while(!s2.empty()){
        Node *temp=s2.top();
        ans.push_back(temp->data);
        s2.pop();
    }
    return ans;
}