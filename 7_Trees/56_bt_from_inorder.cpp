#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
};

int maxi(int inorder[], int start, int end){
    int index = start;
    for(int i=start+1;i<=end;i++){
        if(inorder[index] < inorder[i]){
            index = i;
        }
    }
    return index;
}


node* newNode (int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return Node;
}

node* buildTree (int inorder[], int start, int end)
{
    if(start>end)
        return NULL;

    int maxIndex = maxi(inorder, start, end);
    node* root = newNode(inorder[maxIndex]);
    if(start==end)
        return root;
    root->left = buildTree(inorder, start, maxIndex-1);
    root->right = buildTree(inorder, maxIndex+1, end);
    return root;
}

void printInorder (node* node)
{
	if (node == NULL)
		return;
	printInorder (node->left);
	cout<<node->data<<" ";
	printInorder (node->right);
}

int main()
{
	int inorder[] = {5, 10, 40, 30, 28};
	int len = sizeof(inorder)/sizeof(inorder[0]);
	node *root = buildTree(inorder, 0, len - 1);
	cout << "Inorder traversal of the constructed tree is \n";
	printInorder(root);
	return 0;
}
