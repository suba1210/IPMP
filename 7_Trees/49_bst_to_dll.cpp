class Solution
{
    public:
    Node* newHead=NULL;
    Node* prev=NULL;
    void func(Node* root){
        if(root==NULL)
            return;
        func(root->left);
        if(prev==NULL){
            newHead = root;
        }
        else{
            prev->right=root;
            root->left = prev;
        }
        prev = root;
        func(root->right);
    }
    Node * bToDLL(Node *root)
    {
        func(root);
        return newHead;
    }
};
