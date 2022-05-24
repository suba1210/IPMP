class Solution{
    public:
    
    void func(Node* root, int* maxsum, int sum){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            sum+=root->data;
            *maxsum = max(sum, *maxsum);
        }
        func(root->left, maxsum, sum+root->data);
        func(root->right, maxsum, sum+root->data);
    }
    
    int maxPathSum(Node* root)
    {
        if(root==NULL)
            return 0;
        int maxsum=INT_MIN;
        func(root, &maxsum, 0);
        return maxsum;
    }
};
