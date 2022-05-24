class Solution {
  private:
    Node* prev=NULL;
    Node* first=NULL;
    Node* mid=NULL;
    Node* last=NULL;
    
    void inorder(Node* root){
        if(root==NULL)
            return;
            
        inorder(root->left);
        if(prev!=NULL && prev->data > root->data){
            if(first==NULL){
                    first = prev;
                    mid = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        
        inorder(root->right);
    }
    
  public:
    void correctBST( struct Node* root )
    {
        Node* prev = new Node(INT_MIN);
        inorder(root);
        
        if(first && last){
            swap(first->data, last->data);
        }
        else if(first && mid){
            swap(first->data, mid->data);
        }
    }
};