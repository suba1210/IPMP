void func(struct Node* root, int k, vector<int>& ans){
    if(root==NULL)
        return;
    if(k==0){
        ans.push_back(root->data);
        return;
    }
    func(root->left,k-1,ans);
    func(root->right,k-1,ans);
}

vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> ans;
    func(root,k,ans);
    return ans;
    
}