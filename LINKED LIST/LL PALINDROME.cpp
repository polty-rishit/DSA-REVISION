#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data,Node *next){
        this->data=data;
        this->next=next;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node *mid(Node *head){
    Node *fast=head,*slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

bool palindrome(Node *head){
    Node* cur=mid(head);
    Node *prev=NULL;
    while(cur){
        Node *temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    Node *left=head,*right=prev;
    while(left && right){
        if(left->data!=right->data)return false;
        left=left->next;
        right=right->next;
    }
    return true;
}