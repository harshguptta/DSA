#include<bits/stdc++.h>
using namespace std;

// M-1

bool isPalindrome(ListNode* head) {
    stack<int> st;
    ListNode* temp=head;
    while(temp!=NULL){
        st.push(temp->val);
        temp=temp->next;
    }
    while(head!=NULL){
        int x=st.top();
        st.pop();
        if(x!=head->val)
            return false;
        head=head->next;  
    }
    return true;
}

// M-2

ListNode* reverseLL(ListNode* head){
    ListNode* c=head;
    ListNode* p=NULL;
    ListNode* n=NULL;
    while(c!=NULL){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    return p;
}
bool isPalindrome(ListNode* head) {
    if(head==NULL or head->next==NULL) return true;
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=reverseLL(slow->next);
    slow=slow->next;
    while(slow!=NULL){
        if(slow->val!=head->val)
            return false;
        slow=slow->next;
        head=head->next;
    }
    return true;
}