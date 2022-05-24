class Solution{
    public:
    Node* func(int in[], int inStart, int inEnd, int pre[], int preStart, int preEnd, unordered_map<int, int> inMap){
        if((inStart > inEnd)||(preStart > preEnd)){
            return NULL;
        }
        Node* root = new Node(pre[preStart]);
        
        int inIndex = inMap[root->data];
        int numsLeft = inIndex - inStart;
        
        root->left = func(in, inStart, inIndex-1, pre, preStart+1, preStart+numsLeft, inMap);
        root->right = func(in, inIndex+1, inEnd, pre, preStart+numsLeft+1, preEnd, inMap);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        unordered_map<int, int> inMap;
        
        for(int i=0;i<n;i++){
            inMap[in[i]] = i;
        }
        
        return func(in, 0, n-1, pre, 0, n-1, inMap);
    }
};
