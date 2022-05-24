Node* func(int n, int pre[], char preLN[], int* index){
    if(n==0 || *index == n)
        return NULL;
    Node* root = new Node(pre[*index]);
    *index = *index + 1;
    
    if(preLN[(*index) - 1]=='N'){
        root->left = func(n,pre,preLN,index);
        root->right = func(n,pre,preLN,index);
    }
    return root;
}


struct Node *constructTree(int n, int pre[], char preLN[])
{
    int index = 0;
    return func(n,pre,preLN,&index);

}