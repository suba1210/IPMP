// Approach:
// 1. This method is dependent on Floyd’s Cycle detection algorithm.
// 2. Detect Loop using Floyd’s Cycle detection algorithm and get the pointer to a loop node.
// 3. Count the number of nodes in loop. Let the count be k.
// 4. Fix one pointer to the head and another to a kth node from the head.
// 5. Move both pointers at the same pace, they will meet at loop starting node.
// 6. Get a pointer to the last node of the loop and make next of it as NULL.


#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
};


void removeLoop(Node* loopNode, Node* head){
	Node* tmp = loopNode;
	int count=1;

	while(tmp->next!=loopNode){
		tmp = tmp->next;
		count++;
	}

	Node* ptr1 = head;
	Node* ptr2 = head;

	int temp = count;

	while(temp--){
		ptr2 = ptr2->next;
	}

	while(ptr1!=ptr2){
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	while(ptr2->next!=ptr1){
		ptr2 = ptr2->next;
	}

	ptr2->next = NULL;

}



void detectAndRemoveLoop(Node* head){
	Node* fast = head;
	Node* slow = head;

	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;

		if(slow==fast)
		{
			removeLoop(slow,head);
			return;
		}
		
	}

	return;
	
}

void printList(struct Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

struct Node* newNode(int key)
{
	struct Node* temp = new Node();
	temp->data = key;
	temp->next = NULL;
	return temp;
}


int main()
{
	struct Node* head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);
	head->next->next->next->next->next = head->next->next;

	detectAndRemoveLoop(head);

	cout << "Linked List after removing loop \n";
	printList(head);
	return 0;
}


// fast and slow based solution
/* 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
    
        ListNode *slow  = head;
        ListNode *fast  = head;
        ListNode *entry = head;
        ListNode *prev  = NULL;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {                      
                while(slow != entry) {
                    prev  = slow;
                    slow  = slow->next;
                    entry = entry->next;
                }
                prev->next = NULL;
                
                while(head!=NULL){
                    cout<<head->val<<" ";
                    head = head->next;
                }
            }
        }
        return NULL;           
    }
};

*/