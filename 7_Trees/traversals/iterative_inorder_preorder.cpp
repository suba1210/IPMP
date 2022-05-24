#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node (int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void inOrder(struct Node *root)
{
    stack<Node*> s;
    Node* curr = root;

    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout<<curr->data<<" ";
        curr = curr->right;
    }
}

void preOrder(struct Node* root){
    stack<Node*> s;
    if(root==NULL)
        return;
    s.push(root);

    while(!s.empty()){
        Node* t = s.top();
        s.pop();
        cout<<t->data<<" ";

        if(t->right)
            s.push(t->right);
        if(t->left)
            s.push(t->left);            
    }

}


int main()
{
	/* Constructed binary tree is
			1
			/ \
		2	 3
		/ \
	4	 5
	*/

	struct Node *root = new Node(1);
	root->left	 = new Node(2);
	root->right	 = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout<<"Inorder : ";
    inOrder(root);

    cout<<"\nPreorder : ";
    preOrder(root);

	return 0;
}
