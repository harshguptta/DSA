#include<bits/stdc++.h>
using namespace std;


ListNode* reverseLL(ListNode* head){
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(curr!=NULL){
        ListNode* n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    return prev;
}
void merge(ListNode* l1,ListNode* l2){
    
    while(l1!=NULL){ //because if LL is odd then l1 will be smaller
       ListNode* l1_next=l1->next;
       ListNode* l2_next=l2->next;
        l1->next=l2;
        if(l1_next==NULL) break;
        l2->next=l1_next;
        l1=l1_next;
        l2=l2_next;
    }
}
void reorderList(ListNode* head) {
    if(head==NULL or head->next==NULL)return;
    ListNode* slow=head;
    ListNode* fast=head;
    ListNode* prev=NULL;
    ListNode* l1=head;
    while(fast!=NULL and fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;
    ListNode* l2=reverseLL(slow);
    merge(l1,l2);
}