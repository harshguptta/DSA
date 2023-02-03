#include<bits/stdc++.h>
using namespace std;

ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL)return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(left>1){
            prev=curr;
            curr=curr->next;
            left--;
            right--;
        }
        ListNode* connection =prev;
        ListNode* tail=curr;
        while(right>0){
            ListNode* nex=curr->next;
            curr->next=prev;
             prev=curr;
            curr=nex;
            right--;
        }
        if(connection!=NULL){
            connection->next=prev;}
        else
            head=prev;
        tail->next=curr;
        return head;
    }