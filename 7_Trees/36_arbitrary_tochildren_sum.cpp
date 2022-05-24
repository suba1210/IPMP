/* C++ Program to convert an arbitrary
binary tree to a tree that hold
children sum property */
#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
	
	node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void increment(node* root, int diff){
    if(root->left){
        root->left->data += diff;
        increment(root->left, diff);
    }
    else if(root->right){
        root->right->data += diff;
        increment(root->right, diff);
    }
}


void convertTree(node* root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    convertTree(root->left);
    convertTree(root->right);

    int ldata = 0, rdata = 0, diff;
    
    if(root->left)
        ldata = root->left->data;
    
    if(root->right)
        rdata = root->right->data;
    
    diff = (ldata + rdata) - root->data;

    if(diff>=0){
        root->data += diff;
    }
    else{
        increment(root, -diff);
    }
}


void printInorder(node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}


int main()
{
	node *root = new node(50);
	root->left = new node(7);
	root->right = new node(2);
	root->left->left = new node(3);
	root->left->right = new node(5);
	root->right->left = new node(1);
	root->right->right = new node(30);
	
	cout << "\nInorder traversal before conversion: " << endl;
	printInorder(root);
	
	convertTree(root);
	
	cout << "\nInorder traversal after conversion: " << endl;
	printInorder(root);
	return 0;
}
