ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL) return head;
    ListNode* start=head;
    while(head!=NULL and head->next!=NULL){
        if(head->val==head->next->val)
        {
            head->next=head->next->next;
        }
        else
            head=head->next;
    }
    return start;
}