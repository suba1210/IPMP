    int func(Node* root, int target, set<int>& s){
        if(root==NULL){
            return 0;
        }
        int left = func(root->left, target, s);
        if(left==1)
            return 1;
            
        if(s.find(target-(root->data)) != s.end())
            return 1;
        else
            s.insert(root->data);
            
        return func(root->right, target, s);
            
    }
    
    int isPairPresent(struct Node *root, int target)
    {
        set<int> s;
        return func(root, target, s);
    }