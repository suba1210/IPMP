class Solution {
  public:
    vector<int> printNearNodes(Node *root, int low, int high) {
        Node* curr = root;
        vector<int> result;
        
        while(curr!=NULL){
            if(curr->left==NULL){
                if(curr->data >=low && curr->data <= high){
                    result.push_back(curr->data);
                }
                curr=curr->right;
            }
            else{
                Node* prev = curr->left;
                
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                
                if(prev->right==NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    if(curr->data >=low && curr->data <= high){
                        result.push_back(curr->data);
                    }
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        
        return result;
    }
};