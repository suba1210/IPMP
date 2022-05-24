vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    queue<Node*> q;
    q.push(root);
    stack<int> s1, s2;
    
    while(!q.empty()){
        int count = q.size();
        
        while(count--){
            Node* t = q.front();
            q.pop();
            s1.push(t->data);
            
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    while(!s2.empty()){
        ans.push_back(s2.top());
        s2.pop();
    }
    
    return ans;
}