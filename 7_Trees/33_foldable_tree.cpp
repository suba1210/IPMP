void mirror(Node* root){
    if(root==NULL)
        return;
    
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    mirror(root->left);
    mirror(root->right);
}

bool isSameStruc(Node* lefty, Node* righty){
    if(lefty==NULL && righty==NULL)
        return true;
    if(lefty==NULL || righty==NULL)
        return false;
    
    return (isSameStruc(lefty->left, righty->left) && isSameStruc(lefty->right, righty->right));
    
}

bool IsFoldable(Node* root)
{
    if(root==NULL)
        return true;
    
    mirror(root->left);
    return isSameStruc(root->left, root->right);
}