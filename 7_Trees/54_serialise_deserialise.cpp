class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string str = "";
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL){
                str += "#,";
            }
            else{
                str += (to_string(temp->val) + ",");
            }
            if(temp!=NULL){
                q.push(temp->left);
                q.push(temp->right);
            }            
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        if(str=="#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#"){
                temp->left = NULL;
            }
            else{
                temp->left = new TreeNode(stoi(str));
                q.push(temp->left);
            }
            
            getline(s,str,',');
            if(str=="#"){
                temp->right = NULL;
            }
            else{
                temp->right = new TreeNode(stoi(str));
                q.push(temp->right);
            }           
        }
        return root;
    }
};