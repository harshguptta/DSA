ListNode* rotateRight(ListNode* head, int k) {
    if(!head or !head->next or k==0) return head;
    ListNode* curr=head;
    int len=1;
    while(curr->next!=NULL){ //can be done in one pass same as "Remove nth node from last" using fast and slow pointer approach instead of calculating length of linked list
        len++;
        curr=curr->next;
    }
    curr->next=head;
    k=k%len;
    k=len-k;
    while(k--) curr=curr->next;
    head=curr->next;
    curr->next=NULL;
    return head;
}