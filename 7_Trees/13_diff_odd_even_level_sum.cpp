class Solution{
  public:
    
    int getLevelDiff(Node *root)
    {
       queue<Node*> q;
       q.push(root);
       int oddSum = 0, evenSum=0;
       bool flag = true;
       
       while(!q.empty()){
           int count = q.size();
           
           while(count--){
               Node* t = q.front();
               q.pop();
               
               if(flag)
                oddSum += t->data;
               else
                evenSum += t->data;
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
           }
           
           flag = !flag;
       }
       
       return oddSum - evenSum;
    }
};