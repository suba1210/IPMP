void Print(node *root, int k1, int k2)
{
    /* base case */
    if ( NULL == root )
        return;
     
    /* Since the desired o/p is sorted,
        recurse for left subtree first
        If root->data is greater than k1,
        then only we can get o/p keys
        in left subtree */
    if ( k1 < root->data )
        Print(root->left, k1, k2);
     
    /* if root's data lies in range,
    then prints root's data */
    if ( k1 <= root->data && k2 >= root->data )
        cout<<root->data<<" ";
     
    /* recursively call the right subtree */
   Print(root->right, k1, k2);
}