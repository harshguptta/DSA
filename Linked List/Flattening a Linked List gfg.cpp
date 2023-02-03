/*  Function which returns the  root of 
    the flattened linked list. */
Node *merge(Node *a,Node *b){
    if(a==NULL)return b;
    if(b==NULL)return a;
    Node* c;
    if(a->data<b->data){
        c=a;
        c->bottom=merge(a->bottom,b);
    }
    else{
        c=b;
        c->bottom=merge(a,b->bottom);
    }
    return c;
}

Node *flatten(Node *root)
{
   if(!root or !root->next)return root;
   root->next=flatten(root->next);
   root=merge(root,root->next);
   return root;
}