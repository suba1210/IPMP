// Approach:
// => make the linked list circular
// => Make kth node's next to NULL
// => K+1th node is head

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void rotate(Node** head, int k){
    Node* temp = *head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = *head;

    Node* ptr1 = *head;

    for(int i=0;i<k-1;i++){
        ptr1 = ptr1->next;
    }

    *head = ptr1->next;
    ptr1->next = NULL;

    
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

/* Function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}


int main(void)
{
	Node* head = NULL;

	// create a list 10->20->30->40->50->60
	for (int i = 60; i > 0; i -= 10)
		push(&head, i);

	cout << "Given linked list \n";
	printList(head);
	rotate(&head, 4);

	cout << "\nRotated Linked list \n";
	printList(head);

	return (0);
}