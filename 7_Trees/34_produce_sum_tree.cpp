int func(Node *root)
{
    if (root == NULL)
        return 0;

    int oldVal = root->data;

    root->data = func(root->left) + func(root->right);

    return root->data + oldVal;
}

void toSumTree(Node *root)
{
    func(root);
}