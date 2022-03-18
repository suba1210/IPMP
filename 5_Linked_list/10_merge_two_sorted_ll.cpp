#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int data;
	Node* next;
};

Node* SortedMerge(Node* a, Node* b){
    Node* result = NULL;
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;

    if(a->data <= b->data){
        result = a;
        result->next = SortedMerge(a->next,b);
    }
    else{
        result = b;
        result->next = SortedMerge(a,b->next);
    }
    return result;
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

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

int main()
{

	Node* res = NULL;
	Node* a = NULL;
	Node* b = NULL;

	push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b, 2);

	res = SortedMerge(a, b);

	cout << "Merged Linked List is: \n";
	printList(res);

	return 0;
}