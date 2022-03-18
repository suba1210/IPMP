// A C++ recursive program to add two linked lists
#include <bits/stdc++.h>
using namespace std;

// A linked List Node
class Node {
public:
	int data;
	Node* next;

};

typedef Node node;

/* A utility function to insert
a node at the beginning of linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node[(sizeof(Node))];

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

void addList(Node* head1, Node* head2, Node** result){
    stack<int> stack1;
    stack<int> stack2;

    Node* x1 = head1;
    while(x1!=NULL){
        stack1.push(x1->data);
        x1=x1->next;
    }

    Node* x2 = head2;
    while(x2!=NULL){
        stack2.push(x2->data);
        x2=x2->next;
    }

    int carry=0, rem;

    while(!stack1.empty() && !stack2.empty()){
        int a = stack1.top();
        int b = stack2.top();

		stack1.pop();
		stack2.pop();

		int sum = a+b+carry;

        rem = sum%10;
        carry = sum/10;

		Node* new_node = new Node[(sizeof(Node))];

		new_node->data = rem;
		new_node->next = *result;
		*result = new_node;
    }

	while(!stack1.empty()){
		int a = stack1.top();
		stack1.pop();
		int sum = a+carry;

		rem=sum%10;
		carry=sum/10;

		Node* new_node = new Node[(sizeof(Node))];
		new_node->data = rem;
		new_node->next = *result;
		*result = new_node;		
	}
	while(!stack2.empty()){
		int a = stack2.top();
		stack2.pop();
		int sum = a+carry;

		rem=sum%10;
		carry=sum/10;

		Node* new_node = new Node[(sizeof(Node))];
		new_node->data = rem;
		new_node->next = *result;
		*result = new_node;		
	}
	if(carry!=0){
		Node* new_node = new Node[(sizeof(Node))];
		new_node->data = carry;
		new_node->next = *result;
		*result = new_node;		
	}

}


// Driver code
int main()
{
	Node *head1 = NULL, *head2 = NULL, *result = NULL;

	int arr1[] = { 9, 9, 9 };
	int arr2[] = { 1, 8 };

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	// Create first list as 9->9->9
	int i;
	for (i = size1 - 1; i >= 0; --i)
		push(&head1, arr1[i]);

	// Create second list as 1->8
	for (i = size2 - 1; i >= 0; --i)
		push(&head2, arr2[i]);

	addList(head1, head2, &result);

	printList(result);

	return 0;
}
