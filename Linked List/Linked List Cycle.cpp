#include<bits/stdc++.h>
using namespace std;

bool hasCycle(ListNode *head) {
    ListNode *slow=head;
    ListNode *fast=head;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
            return true;
    }
    return false;
}