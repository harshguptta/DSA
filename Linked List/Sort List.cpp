 ListNode* middleNode(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
   if(l1==NULL)return l2;
    if(l2==NULL)return l1;
    ListNode* c=NULL;
    if(l1->val<l2->val){
        c=l1;
        c->next=mergeTwoLists(l1->next,l2);
    }else{
        c=l2;
        c->next=mergeTwoLists(l1,l2->next);
    }
    return c;
}
ListNode* sortList(ListNode* head) {
    if(!head or !head->next)return head;
    ListNode* mid=middleNode(head);
    ListNode* a=head;
    ListNode* b=mid->next;
    mid->next=NULL;
    a=sortList(a);
    b=sortList(b);
    ListNode* c=mergeTwoLists(a,b);
    return c;
}