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

vector<int> postOrder(Node *root){
    vector<int>ans;
    Node *curr=root;
    stack<Node*>s;
    while(curr!=NULL || !s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }else{
            Node *temp=s.top()->right;
            if(temp==NULL){
                temp=s.top();
                s.pop();
                ans.push_back(temp->data);
                while(!s.empty() && temp==s.top()->right){
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->data);
                }
            }else curr=temp;
        }
    }
    return ans;
}