class Solution{
  public:
    
    vector<int> Ancestors(struct Node *root, int target)
    {
        vector<int> ans;
        if(root==NULL)
            return ans;
        stack<Node*> stk;
        
        while(true){
            while(root && root->data != target){
                stk.push(root);
                root = root->left;
            }
            
            if(root && root->data == target){
                break;
            }
            
            if(!stk.empty() && stk.top()->right==NULL){
                root = stk.top();
                stk.pop();
                
                if(!stk.empty() && root==stk.top()->right){
                    root = stk.top();
                    stk.pop();
                }
            }
            root = (stk.empty()) ? NULL : stk.top()->right;
        }
        
        while(!stk.empty()){
            ans.push_back(stk.top()->data);
            stk.pop();
        }
        
        return ans;
    }
};