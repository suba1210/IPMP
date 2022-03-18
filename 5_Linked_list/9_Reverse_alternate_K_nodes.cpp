// Approach:
// -> reverse the first k nodes
// -> for head->next, we first assign NULL, then we re assign it by calling a function

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};


Node* reverse(Node* head, int k)
{
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;

    int count = 0;

    while(current!=NULL && count<k){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if(head!=NULL){
        head->next = current;
    }
	
	// already current is pointing to the start of next k nodes, so, moving k-1 times would be sufficient
	for(int i=0;i<k-1 &&  current!=NULL;i++){
		current = current->next;
	}

	if(current!=NULL){
		current->next = reverse(current->next, k);
	}

	return prev;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}


void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}


int main()
{
	Node* head = NULL;
	push(&head, 10);
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);

	cout << "Given linked list \n";
	printList(head);
	head = reverse(head, 3);

	cout << "\nReversed Linked list \n";
	printList(head);

	return (0);
}
