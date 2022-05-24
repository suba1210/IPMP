// do reverse inorder traversal

class Solution {
public:
    void func(TreeNode* root, int* sum){
        if(root==NULL)
            return;
        func(root->right, sum);
        *sum = *sum + root->val;
        root->val = *sum;
        func(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        func(root, &sum);
        return root;
        
    }
};