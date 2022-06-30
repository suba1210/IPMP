class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==NULL)
            return NULL;
        
        // here we are deleting, so node structure would have changed, that is why we are assigning
        root->left = trimBST(root->left, low, high); 
        root->right = trimBST(root->right, low, high);
        
        // if root->val < low then everything on the left of root would be lesser than low,
        // so assign it to be its right subtree
        if(root && root->val < low){
            root = root->right;
        }
        
        // the vice versa applies here
        if(root && root->val > high){
            root = root->left;
        }
        
        return root;
        
    }
};