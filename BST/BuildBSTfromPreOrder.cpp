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

    Node *build(vector<int>&nums,int &i,int bound){
        if(i==nums.size() || nums[i]>=bound)return NULL;
        Node *root=new Node(nums[i++]);
        root->left=build(nums,i,root->data);
        root->right=build(nums,i,bound);
        return root;
    }
    
    Node* preToBST(vector<int>&nums) {
        // code here
        int i=0;
        return build(nums,i,INT_MAX);
    }