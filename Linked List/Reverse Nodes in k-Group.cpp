#include<bits/stdc++.h>
using namespace std;

ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or k==1)return head;
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode *cur=dummy,*nex=dummy,*pre=dummy;
        int count=0;
        while(cur->next!=NULL){
            count++;
            cur=cur->next;
        }
        while(count>=k){
            cur=pre->next;
            nex=cur->next;
            for(int i=1;i<k;i++){
                cur->next=nex->next; //write this line only --> for following three lines --> each line start with (left side expression) of previous line
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            count-=k;
            pre=cur;
        }
        return dummy->next;
    }