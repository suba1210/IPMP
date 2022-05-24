class Solution{
    public:
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> ans;
        if(root==NULL)
            return ans;
    	bool flag = true;
    	deque<Node*> dq;
    	dq.push_back(root);
    	
    	while(!dq.empty()){
    	    int count = dq.size();
    	    
    	    while(count--){
    	        if(flag){
    	            Node* t = dq.front();
    	            dq.pop_front();
    	            ans.push_back(t->data);
    	            if(t->left)
    	                dq.push_back(t->left);
    	            if(t->right)
    	                dq.push_back(t->right);
    	        }
    	        else{
    	            Node* t = dq.back();
    	            dq.pop_back();
    	            ans.push_back(t->data);
    	            if(t->right)
    	                dq.push_front(t->right);
    	            if(t->left)
    	                dq.push_front(t->left);
    	        }
    	    }
    	    flag = !flag;
    	}
    	
    	return ans;
    }
};