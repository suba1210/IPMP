    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* succ = NULL;
        
        while(root != NULL){
            if(root->data <= x->data){
                root = root->right;
            }
            else{
                succ = root;
                root= root->left;
            }
        }
        return succ;
    }