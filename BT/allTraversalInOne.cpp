#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data;
        this->left=NULL;
        this->right=NULL;
    }
};

vector<int> preInPostTraversal(Node *root){
    stack<pair<Node *,int>>s;
    s.push({root,1});
    if(root==NULL)return;
    vector<int>pre,post,in;
    while(!s.empty()){
        auto i=s.top();
        s.pop();
        if(i.second==1){
            pre.push_back(i.first->data);
            i.second++;
            s.push(i);
        }else if(i.second==2){
            in.push_back(i.first->data);
            i.second++;
            s.push(i);
            if(i.first->right!=NULL)s.push({i.first->right,1});
        }
        else post.push_back(i.first->data);
    }
}