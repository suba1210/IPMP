    int height(Node* root){
        if(root==NULL)
            return 0;
        return (1 + max(height(root->left), height(root->right)));
    }
    
    int diameter(Node* root) {
        if(root == NULL)
            return 0;
        int lDepth = height(root->left);
        int rDepth = height(root->right);
        
        int lDia = diameter(root->left);
        int rDia = diameter(root->right);
        
        return max(lDepth + rDepth + 1, max(lDia, rDia));
    }