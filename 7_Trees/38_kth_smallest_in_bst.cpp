    
// O(N) space - considering space of recursion call stack    
    Node* helperFunc(Node* root, int k, int* count){
        if(root==NULL){
            return root;
        }
        Node* left = helperFunc(root->left, k, count);
        
        if(left!=NULL)
            return left;
        
        *count = *count + 1;
        if(k == *count)
            return root;
            
        return helperFunc(root->right, k, count);
    }
    int KthSmallestElement(Node *root, int k) {
        int count = 0;
        Node* ans = helperFunc(root, k, &count);
        if(ans==NULL)
            return -1;
        else{
            return ans->data;
        }
    }

// O(1) space => Morris traversal

class Solution {
  public:
    int KthSmallestElement(Node *root, int k) {
        int count=0;
        while(root!=NULL){
            if(root->left==NULL){
                count++;
                if(k==count)
                    return root->data;
                root = root->right;
            }
            else{
                Node* prev = root->left;

                while(prev->right && prev->right!=root){
                    prev = prev->right;
                }
                if(prev->right==NULL){
                    prev->right = root;
                    root = root->left;
                }
                else{
                    count++;
                    if(k==count)
                        return root->data;
                    prev->right = NULL;
                    root = root->right;
                }
            }
        }
        return -1;
    }
};