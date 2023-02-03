Node* copyRandomList(Node* head) {
      
    Node *iter = head; 
    Node *front = head;
    //FIRST PART
     while (iter != NULL) {
        front = iter->next;

        Node *copy = new Node(iter->val);
        iter->next = copy;
        copy->next = front;

        iter = front;
      }
    
    //SECOND PART
    iter = head;
      while (iter != NULL) {
        if (iter->random != NULL) {
          iter->next->random = iter->random->next;
        }
        iter = iter->next->next;
      }
    
    //THIRD PART
    iter = head;
      Node *pseudoHead = new Node(0);
      Node *copy = pseudoHead;

      while (iter != NULL) {
        front = iter->next->next;

        // extract the copy
        copy->next = iter->next;

        // restore the original list
        iter->next = front;
          
        copy = copy -> next; 
        iter = front;
      }

      return pseudoHead->next;
}