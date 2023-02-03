bool isSubPath(ListNode* head, TreeNode* root) {
  return dfs(head,root);  
}
bool dfs(ListNode* head, TreeNode* root){
    if(root==NULL) return false;
    if(match(head,root))return true; // from this root of the tree, we are assuming that whole continuous LL will be found
    return dfs(head,root->left) || dfs(head,root->right);//if not then try for left root and right root
}
bool match(ListNode* head, TreeNode* root){
    if(head==NULL) return true;
    if(root==NULL or root->val !=head->val) return false;
    return match(head->next,root->left) || match(head->next,root->right);
}