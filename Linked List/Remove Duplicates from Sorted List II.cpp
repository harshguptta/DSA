ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL) return head;
    ListNode* start=new ListNode();
    start->next=head;
    ListNode* prev=start;
    while(head!=NULL){
        if(head->next!=NULL and head->val==head->next->val)
        {
            while(head->next!=NULL and head->val==head->next->val)
                head=head->next;
            prev->next=head->next;
        }
        else{
            prev=prev->next;
        }
        head=head->next;
    }
    return start->next;
}