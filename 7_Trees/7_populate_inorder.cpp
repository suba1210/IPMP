/* 
Do reverse inorder traversal and store the next pointers as previous elements of the traversal
*/
    
    void populate(Node* root, Node** nextRef){
        if(root!=NULL){
            populate(root->right, nextRef);
            root->next = *nextRef;
            *nextRef = root;
            populate(root->left, nextRef);
        }
    }

    void populateNext(Node *root)
    {
        Node* nextRef = NULL;
        populate(root, &nextRef);
    }