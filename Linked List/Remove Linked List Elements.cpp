#include<bits/stdc++.h>
using namespace std;

ListNode* removeElements(ListNode* head, int k) {
    if(!head)return head;
    ListNode* start=new ListNode();
    start->next=head;
    ListNode* curr=start;
    while(curr!=NULL and curr->next!=NULL){
        if(curr->next->val==k)
            curr->next=curr->next->next;
        else
            curr=curr->next;
    }
    return start->next;
}