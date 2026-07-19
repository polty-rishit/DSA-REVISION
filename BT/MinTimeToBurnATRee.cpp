#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void parent(Node* root,unordered_map<Node*,Node*>&hsh){
        if(root==NULL)return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* temp=q.front();
                q.pop();
                
                if(temp->left){
                    hsh[temp->left]=temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    hsh[temp->right]=temp;
                    q.push(temp->right);
                }
            }
        }
    }
    
Node* find(Node* root,int target){
    if(root==NULL)return NULL;
    if(root->data==target)return root;
    Node *left=find(root->left,target);
    if(left)return left;
    return find(root->right,target);
}

int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*>hsh;
        parent(root,hsh);
        Node *t=find(root,target);
        unordered_map<Node*,bool>vis;
        vis[t]=1;
        queue<Node*>q;
        q.push(t);
        int d=0;
        while(!q.empty()){
            int n=q.size();
            d++;
            for(int i=0;i<n;i++){
                Node *node=q.front();
                q.pop();
                
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(hsh[node] && !vis[hsh[node]]){
                    q.push(hsh[node]);
                    vis[hsh[node]]=1;
                }
            }
        }
        return d-1;
    }