#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	struct Node* next;
};


void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(
			sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

int countNodes(struct Node* head){
    struct Node* temp = head;
    int count=0;
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }
    return count;
}



void swapKth(struct Node** head_ref, int k)
{
    int count = countNodes(*head_ref);

    if(k>count || k==1)
        return;

    if((2*k)-1 == count)
        return;

    struct Node* first_node = *head_ref;
    struct Node* first_prev = NULL;

    struct Node* end_node = *head_ref;

    struct Node* second_node = *head_ref;
    struct Node* second_prev = NULL;    

    for(int i=1;i<k;i++){
        first_prev = first_node;
        first_node = first_node->next;
    }

    for(int i=1;i<(count-k+1);i++){
        second_prev = second_node;
        second_node = second_node->next;
    }

    if(first_prev)
        first_prev->next = second_node;

    if(second_prev)
        second_prev->next = first_node;

    struct Node* temp = first_node->next;
    first_node->next = second_node->next;
    second_node->next = temp;

    if(k==1)
        *head_ref = second_node;
    else if(k==count)
        *head_ref = first_node;


}


int main()
{
	// 1->2->3->4->5->6->7->8
	struct Node* head = NULL;
	for (int i = 8; i >= 1; i--)
		push(&head, i);

	cout << "Original Linked List: ";
	printList(head);

	swapKth(&head, 3);
	printList(head);

	return 0;
}
