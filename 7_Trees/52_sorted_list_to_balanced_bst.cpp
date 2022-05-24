class Solution{
  public:
    int countNodes(LNode* head){
        LNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
    TNode* func(LNode** head, int n){
        if(n<=0)
            return NULL;
        TNode* lefty = func(head, n/2);
        TNode* root = new TNode((*head)->data);
        root->left = lefty;
        *head = (*head)->next;
        root->right = func(head, n-n/2-1);
        return root;
    }
    TNode* sortedListToBST(LNode *head) {
        int n = countNodes(head);
        return func(&head, n);
    }
};