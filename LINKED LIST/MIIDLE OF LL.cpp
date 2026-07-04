#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data,Node *next){
        this->data=data;
        this->next=next;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

// we can find the midlle of the Linked List in both the fashion.
Node* mid(Node *head){
    Node *fast=head,*slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* mid(Node *head){
    Node *fast=head,*slow=head;
    while(fast && fast->next){
        fast=fast->next;
        if(fast->next)fast=fast->next;
        slow=slow->next;
    }
    return slow;
}