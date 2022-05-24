vector<int> helper(int x, vector<int> path){
    path.push_back(x);
    return path;
}

void func(Node* root, vector<vector<int> >& paths, vector<int> path){
    if(root==NULL)
        return;
    
    if(root->right==NULL && root->left==NULL){
        path.push_back(root->data);
        paths.push_back(path);
    }
    
    func(root->left, paths, helper(root->data, path));
    func(root->right, paths, helper(root->data, path));
}

vector<vector<int>> Paths(Node* root)
{
    vector<vector<int> > paths;
    
    if(root==NULL)
        return paths;
        
    vector<int> path;
    func(root, paths, path);
    
    return paths;
}