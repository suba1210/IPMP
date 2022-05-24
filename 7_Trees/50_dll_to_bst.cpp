#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
	Node* prev;
};

int countNodes(Node* root){
    Node* temp = root;
    int count = 0;
    while(root!=NULL){
        count++;
        root=root->next;
    }
    return count;
}

Node* func(Node** head, int n){
    if(n<=0){
        return NULL;
    }
    Node* left = func(head, n/2);
    Node* root = *head;
    root->prev = left;
    *head = (*head)->next;
    root->next = func(head, n-n/2-1);
    return root;
}

Node* sortedListToBST(Node* root){
    int n = countNodes(root);
    return func(&root, n); // without passing as reference it doesn't work
}


void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);
	if((*head_ref) != NULL)
	(*head_ref)->prev = new_node ;
	(*head_ref) = new_node;
}

void printList(Node *node)
{
	while (node!=NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}

void preOrder(Node* node)
{
	if (node == NULL)
		return;
	cout<<node->data<<" ";
	preOrder(node->prev);
	preOrder(node->next);
}

int main()
{
	Node* head = NULL;
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	cout<<"Given Linked List\n";
	printList(head);
	Node *root = sortedListToBST(head);
	cout<<"\nPreOrder Traversal of constructed BST \n ";
	preOrder(root);

	return 0;
}
