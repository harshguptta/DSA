#include<bits/stdc++.h>
using namespace std;

ListNode *detectCycle(ListNode *head) {
    if(!head or head->next==NULL)return NULL;
   ListNode *slow=head;
    ListNode *fast=head;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)break;
    }
    if(slow!=fast)return NULL;
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}