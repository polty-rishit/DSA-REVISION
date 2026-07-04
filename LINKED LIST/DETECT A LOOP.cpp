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

bool isLoopPresent(Node *head){
    Node *fast=head,*slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)return true;
    }
    return false;
}