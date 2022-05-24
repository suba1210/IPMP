class Solution
{
    public:

    bool func(Node* root, int S, int sum){
        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL){
            sum += root->data;
            if(sum==S)
                return true;
            else
                return false;
        }
        bool left = func(root->left, S, sum+root->data);
        bool right = func(root->right, S, sum+root->data);
        
        if(left||right){
            return true;
        }
        return false;
    }    
    
    bool hasPathSum(Node *root, int S) {
        if(root==NULL)
            return false;
        return func(root, S, 0);
    }
};