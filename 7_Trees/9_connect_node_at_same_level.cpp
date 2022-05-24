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
                    t->next = NULL;
                }
                else{
                    t->next = q.front();
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
                n->left->next = n->right;
                if(n->next == NULL){
                    break;
                }
                n->right->next = n->next->left;
                n = n->next;
            }
            temp = temp->left;
            
        }
        
        return root;
    }
};
