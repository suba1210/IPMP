class Solution {
public:
    
    bool func(TreeNode* root, int limit, int sum){
        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL){
            if(sum+root->val >= limit)
                return true;
            return false;
        }
        
        bool left = func(root->left, limit, sum+root->val);
        bool right = func(root->right, limit, sum+root->val);
        
        if(!left)
            root->left = NULL;
        if(!right)
            root->right = NULL;
        
        if(left || right)
            return true;
        
        return false;
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root==NULL)
            return NULL;
        bool ans = func(root, limit, 0);
            
        if(ans)
            return root;
        else
            return NULL;
    }
};