#include<bits/stdc++.h>
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head or head->next==NULL)return NULL;
    ListNode* slow=head;
    ListNode* fast=head;
    while(n--){
        fast=fast->next;
    }
    ListNode* prev=NULL;
    while(fast!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next;
    }
   if(prev!=NULL)
       prev->next=slow->next;
    else
        return slow->next;
    
    return head;
}