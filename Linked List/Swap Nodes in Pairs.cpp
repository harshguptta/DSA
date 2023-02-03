#include<bits/stdc++.h>
using namespace std;

ListNode* swapPairs(ListNode* head) {
    if(head==NULL or head->next==NULL)
        return head;
    // Using an extra node for making work easier
    //See nick white video
    ListNode* temp=new ListNode();
    temp->next=head;
    ListNode* curr=temp;
    while(curr->next!=NULL and curr->next->next!=NULL){
        ListNode* firstnode=curr->next;
        ListNode* secnode=curr->next->next;
        firstnode->next=secnode->next;
        secnode->next=firstnode;
        curr->next=secnode;
        curr=curr->next->next;
    }
    return temp->next;
}