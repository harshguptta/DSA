//M-1

class cmp
{
    public :

    bool operator() (ListNode *a , ListNode *b)
    {
        return a -> val > b -> val ;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    // Our Priority Queue q will always store the K Smallest Elements from the K Sorted Lists

    priority_queue<ListNode* , vector<ListNode*> , cmp> q ;

    // Firstly, we enter all the K Nodes into our Min-Heap

    for(int i = 0 ; i < lists.size() ; i++)
    {
        if(lists[i] != NULL)
            q.push(lists[i]) ;
    }

    // Dummy Pointer's Nexy will point to the Head of our K Merged Sorted Linkedlist

    ListNode *dummy = new ListNode(-1) ;

    // Tail pointer will help us to add Nodes into our K Merged Sorted LinkedList

    ListNode *tail = dummy ;

    // While Loop will run till our the size of our Priority-Queue not becomes 0(zero)

    while(q.size() )
    {
        // We pop the Topmost Element from our Priority-Queue and store it in Temp pointer

        ListNode *temp = q.top() ;
        q.pop() ;

        // Tail's Next points to Temp

        tail -> next = temp ;

        // After that, Tail Pointer is moved to Temp

        tail = temp ;

        // We enter Temp's Next Node into our Priority-Queue if it exists

        if(temp -> next != NULL)
            q.push(temp -> next) ;
    }

    // At the end, we return Dummy's Next which contains the Head of our Merged K Sorted LinkedList

    return dummy -> next ;
}
};



//M-2


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