class Solution{
  public:
    bool check(Node *root)
    {
        int leafLevel = -1;
        return checkFunc(root, &leafLevel, 0);
    }
    
    bool checkFunc(Node* root, int *leafLevel, int leafCount){
    if (root == NULL) return true;
    
    if (root->left == NULL && root->right == NULL)
    {
        if (*leafLevel == -1)
        {
            *leafLevel = leafCount; 
            return true;
        }
 
        return (leafCount == *leafLevel);
    }
    
    return checkFunc(root->left, leafLevel, leafCount+1) && checkFunc(root->right, leafLevel, leafCount+1);
    }
};