    int height(Node* root){
        if(root==NULL)
            return 0;
            
        int lh = height(root->left);
        int rh = height(root->right);
        
        if(abs(lh-rh)>1 || lh == -1 || rh==-1)
            return -1;
        
        return 1 + max(lh, rh);        
    }

    bool isBalanced(Node *root)
    {
        if(height(root)==-1){
            return false;
        }
        return true;
    }