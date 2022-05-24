    vector<int> levelOrder(Node* node)
    {
        queue<Node*> q;
        q.push(node);
        vector<int> ans;
        
        while(!q.empty()){
            Node* t = q.front();
            q.pop();
            ans.push_back(t->data);
            
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        
        return ans;
    }