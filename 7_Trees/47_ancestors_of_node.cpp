bool func(struct Node *root, int target, vector<int> &result)
{
    if (root == NULL)
        return false;

    if (root->data == target)
    {
        return true;
    }

    if (func(root->left, target, result) || func(root->right, target, result))
    {
        result.push_back(root->data);
        return true;
    }

    return false;
}

vector<int> Ancestors(struct Node *root, int target)
{
    vector<int> result;
    func(root, target, result);
    return result;
}