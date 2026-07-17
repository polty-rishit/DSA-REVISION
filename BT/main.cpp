#include<bits/stdc++.h>
using namespace std;

class BinaryTree{
    public:
    int data;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int data,BinaryTree *left,BinaryTree *right){
        this->data=data;
        this->left=left;
        this->right=right;
    }

    BinaryTree(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void lvl(BinaryTree *root,vector<int>&ans){
        queue<BinaryTree *>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                BinaryTree *temp=q.front();
                q.pop();
                ans.push_back(temp->data);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
    }

void print(vector<int>&ans){
    for(auto i:ans)cout<<i<<" ";
}

int main(){
    BinaryTree *root=new BinaryTree(1);
    root->left=new BinaryTree(2);
    root->right=new BinaryTree(3);
    vector<int>ans;
    lvl(root,ans);
    print(ans);
}