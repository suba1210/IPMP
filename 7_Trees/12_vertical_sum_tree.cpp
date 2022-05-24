class Solution{
  public:
    void verticalSumFunc(Node* root, map<int, int>& m, int hd){
        if(root==NULL)
            return;
        verticalSumFunc(root->left, m, hd-1);
        m[hd] += root->data;
        verticalSumFunc(root->right, m, hd+1);
    }
  
    vector <int> verticalSum(Node *root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int, int> m;
        verticalSumFunc(root, m, 0);
        
        for(auto x : m){
            ans.push_back(x.second);
        }
        
        return ans;
    }
};