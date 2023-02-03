//M-1

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
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.empty()){
    return NULL;
}
    while(lists.size()>1){
    lists.push_back(mergeTwoLists(lists[0],lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}