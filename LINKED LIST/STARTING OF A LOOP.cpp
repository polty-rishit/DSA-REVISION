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

Node* mid(Node *head){
    Node *fast=head,*slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)return slow;
    }
    return NULL;
}

Node* loop(Node *head){
    if(!head)return NULL;
    Node *inter=mid(head);
    if(!inter)return NULL;
    Node *cur=head;
    while(cur!=inter){
        cur=cur->next;
        inter=inter->next;
    }
    return cur;
}