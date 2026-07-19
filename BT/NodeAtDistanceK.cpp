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
            Node *temp=q.front();
            q.pop();
            
            if(temp->left){
                q.push(temp->left);
                hsh[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                hsh[temp->right]=temp;
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

vector<int> nodesAtDistanceK(Node *root,int target,int k){
    unordered_map<Node*,Node*>hsh;
    parent(root,hsh);
    unordered_map<Node*,int>vis;
    Node *t=find(root,target);
    vis[t]=1;
    queue<Node*>q;
    q.push(t);
    int d=0;
    while(!q.empty()){
        int n=q.size();
        if(d++==k)break;
        for(int i=0;i<n;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left && !vis[temp->left]){
                q.push(temp->left);
                vis[temp->left]=1;
            }
            if(temp->right && !vis[temp->right]){
                q.push(temp->right);
                vis[temp->right]=1;
            }
            if(hsh[temp] && !vis[hsh[temp]]){
                q.push(hsh[temp]);
                vis[hsh[temp]]=1;
            }
        }
    }
    vector<int>ans;
    while(!q.empty()){
        Node* node=q.front();
        ans.push_back(node->data);
        q.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}