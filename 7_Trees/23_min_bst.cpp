int minValue(struct Node *root) {
    if(root==NULL)
        return -1;
    if(root->left==NULL)
        return root->data;
    minValue(root->left);
}