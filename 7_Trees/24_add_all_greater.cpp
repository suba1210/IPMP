void  inorderTraversal(Node* root, int* sum){
    if(root==NULL)
        return;
    inorderTraversal(root->right, sum);
    
    *sum = *sum + root->data;
    root->data = *sum;
    
    inorderTraversal(root->left, sum);
}


Node* modify(Node *root)
{
    vector<int> inorder;
    int sum  = 0;
    inorderTraversal(root, &sum);
    return root;
}