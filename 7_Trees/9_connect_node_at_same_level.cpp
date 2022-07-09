// with non constant extra space
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        int i;
        while(!q.empty()){
            int count = q.size();
            Node* t;
            for(i=0;i<count;i++){
                t = q.front();
                q.pop();
                
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
                if(count == i+1){
                    t->nextRight = NULL;
                }
                else{
                    t->nextRight = q.front();
                }
            }
        }
        return root;
    }
};

// using constant extra space
class Solution {
public:
    Node* connect(Node* root) {
        Node* temp = root;
        
        while(temp!=NULL && temp->left!=NULL){
            Node* n = temp;
            
            while(true){
                n->left->nextRight = n->right;
                if(n->nextRight == NULL){
                    break;
                }
                n->right->nextRight = n->nextRight->left;
                n = n->nextRight;
            }
            temp = temp->left;
            
        }
        
        return root;
    }
};
