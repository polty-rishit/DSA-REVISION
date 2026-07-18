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

void lvl(Node *root,vector<int>&ans,int &flag){
        if(!root)return;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>fin;
            for(int i=0;i<n;i++){
                Node *temp=q.front();
                q.pop();
                fin.push_back(temp->data);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            if(flag==1)reverse(fin.begin(),fin.end());
            ans.insert(ans.end(),fin.begin(),fin.end());
            flag^=1;
        }
}

vector<int> zigZag(Node *root){
        int flag=0;
        vector<int>ans;
        lvl(root,ans,flag);
        return ans;
}