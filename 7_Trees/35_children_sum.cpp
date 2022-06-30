int isSumProperty(Node *root)
{
    if (root == NULL)
        return 1;
    if (root->left == NULL && root->right == NULL)
        return 1;

    int x = 0;
    if (root->left)
        x += root->left->data;
    if (root->right)
        x += root->right->data;

    return ((root->data == x) && isSumProperty(root->left) && isSumProperty(root->right));
}