#include<bits/stdc++.h>
using namespace std;

ListNode* insertionSortList(ListNode* head) {
    ListNode* start=new ListNode();
    start->next=head;
    ListNode* prev=start;
    ListNode* curr=head;
    while(curr!=NULL){
        if(curr->next and curr->next->val<curr->val){
            while(prev->next and prev->next->val<curr->next->val){
                prev=prev->next;
            }
            ListNode* temp=prev->next;
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev->next->next=temp;
            prev=start;
        }else
            curr=curr->next;
    }
    return start->next;
}
    
