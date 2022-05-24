int getMaxWidth(Node* root) {
    queue<Node*> q;
    q.push(root);
    int maxWidth = 1;
    while(!q.empty()){
        int count = q.size();
        maxWidth = max(maxWidth, count);
        
        while(count--){
            Node* top = q.front();
            q.pop();
            if(top->left!=NULL){
                q.push(top->left);
            }
            if(top->right!=NULL){
                q.push(top->right);
            }
        }
    }
    return maxWidth;
}