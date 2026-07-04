#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data,Node*next){
        this->data=data;
        this->next=next;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node *cycle(Node *head){
    Node *fast=head,*slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)return slow;
    }
    return NULL;
}

Node *start(Node *head){
    if(!head)return NULL;
    Node *inter=cycle(head);
    if(!inter)return NULL;
    Node *cur=head;
    while(cur!=inter){
        cur=cur->next;
        inter=inter->next;
    }
    return cur;
}
int lengthOfLoop(Node *head){
    if(!head)return NULL;
    Node *s=start(head);
    if(!s)return NULL;
    int count=1;
    Node *temp=s->next;
    while(temp!=s){
        temp=temp->next;
        count++;
    }
    return count;
}