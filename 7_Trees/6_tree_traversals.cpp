void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);   
}

void postorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    inorder(root->right);  
    cout<<root->data<<" ";   
}

