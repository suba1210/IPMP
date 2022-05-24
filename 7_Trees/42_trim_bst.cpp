class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL)
            return NULL;
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        if(root && root->val < low){
            root = root->right;
        }
        
        if(root && root->val > high){
            root = root->left;
        }
        
        return root;
        
    }
};