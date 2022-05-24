// do line by line level order traversal and print the first node of each level


vector<int> leftView(Node *root)
{
   vector<int> ans;
   if(root==NULL)
    return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int count = q.size();
        
        for(int i=0;i<count;i++){
            Node* t = q.front();
            q.pop();
            if(i==0){
                ans.push_back(t->data);
            }
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
    }
    return ans;
}