class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        node* c = head;
    	node* p = NULL;
    	node* n;
    	int x = k;
    	while (c != NULL && x > 0) {
    		n = c->next;
    		c->next = p;
    		p = c;
    		c = n;
    		x--;
    	}
    	if (c != NULL) {
    		head->next = reverse(c, k);
    	}
    	return p;
    }
};