    bool isIdentical(Node *r1, Node *r2)
    {
        // when both trees are NULL
        if(r1==NULL && r2==NULL){
            return true;
        }
        //when both are not NULL => check its data, check its right amd check its left
        else if(r1 !=NULL && r2 !=NULL){
            return (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
        }
        // when one is NULL and other is not
        else{
            return false;
        }
    }