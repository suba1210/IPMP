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

void postOrder(struct Node* root){
    stack<Node*> s1, s2;
    Node* curr = root;

    s1.push(curr);

    while(!s1.empty()){
        Node* t = s1.top();
        s1.pop();
        s2.push(t);

        if(t->left)
            s1.push(t->left);
        if(t->right)
            s1.push(t->right);
    }

    while(!s2.empty()){
        Node* t = s2.top();
        s2.pop();
        cout<<t->data<<" ";
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

	cout<<"Postorder : ";
    postOrder(root);


	return 0;
}
