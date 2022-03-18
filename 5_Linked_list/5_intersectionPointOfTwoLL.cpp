// Approach:

// 1. Get count of the nodes in the first list, let count be c1.
// 2. Get count of the nodes in the second list, let count be c2.
// 3. Get the difference of counts d = abs(c1 – c2)
// 4. Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes
// 5. Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes


#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};


int getCount(Node* head)
{
	Node* current = head;
	int count = 0;
	while (current != NULL) {
		count++;
		current = current->next;
	}

	return count;
}

int getIntesectionNode(Node* ptr1, Node* ptr2){

    int ptr1Cnt = getCount(ptr1);
    int ptr2Cnt = getCount(ptr2);

    if(ptr1Cnt>ptr2Cnt){
        int diff = ptr1Cnt - ptr2Cnt;
        while(diff--){
            ptr1 = ptr1->next;
        }
    }
    else{
        int diff = ptr2Cnt - ptr1Cnt;
        while(diff--){
            ptr2 = ptr2->next;
        }      
    }

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;

}

int main()
{
	/*
		Create two linked lists
	
		1st 3->6->9->15->30
		2nd 10->15->30
	
		15 is the intersection point
	*/

	Node* newNode;

	Node* head1 = new Node();
	head1->data = 10;

	Node* head2 = new Node();
	head2->data = 3;

	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;

	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	cout << "The node of intersection is " << getIntesectionNode(head1, head2);
}