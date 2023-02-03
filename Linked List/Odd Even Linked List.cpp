#include<bits/stdc++.h>
using namespace std;

ListNode* oddEvenList(ListNode* head) {
    if(!head)return head;
    ListNode* odd_head=head;
    ListNode* even_head=head->next;
    ListNode* odd=head;
    ListNode* even=head->next;
    while(even and even->next){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=even_head;
    return odd_head;
}