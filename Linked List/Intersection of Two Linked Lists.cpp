#include<bits/stdc++.h>
using namespace std;

int len(ListNode* head){
        int cnt=1;
        while(head->next!=NULL){
            cnt++;
            head=head->next;}
        return cnt;
    }
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int l1=len(headA);
    int l2=len(headB);
    int diff=abs(l1-l2);
    if(l1>l2){
        while(diff--){
            headA=headA->next;}
    }
    else{
        while(diff--){
            headB=headB->next;
        }}
    while(headA!=headB){
        headA=headA->next;
        headB=headB->next;
    }
    return headA;
}