ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
   ListNode* temp=new ListNode();
    ListNode* curr=temp;
    int carry=0;
    while(l1!=NULL or l2!=NULL or carry!=0){
        int sum=0;
        if(l1!=NULL){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
         ListNode* node=new ListNode(sum%10);
        curr->next=node;
        curr=curr->next;
    }
    return temp->next; 
}