    bool isCompleteBT(Node* root){
        queue<Node*> que;
        bool firstNull = false;
        que.push(root);
        
        while(!que.empty()){
            Node* t = que.front();
            que.pop();
            
            if(t->left){
                if(!firstNull)
                    que.push(t->left);
                else
                    return false;
            }
            else{
                firstNull = true;
            }
            
            if(t->right){
                if(!firstNull)
                    que.push(t->right);
                else
                    return false;
            }
            else{
                firstNull = true;
            }
        }
        
        return true;
    }