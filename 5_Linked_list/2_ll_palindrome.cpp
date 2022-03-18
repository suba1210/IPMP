// Reverse the linkedlist, and check if both are same.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
}*head;

Node* reverseList(Node* temp)
{
    if(temp==NULL || temp->next == NULL){
        return temp;
    }
    Node* rest_head = reverseList(temp->next);
    Node* rest_tail = temp->next;
    rest_tail->next = temp;
    temp->next = NULL;
    return rest_head;
}

bool isPalindrome(){

    // reverse 
    Node* slow = head;
    Node* fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast = fast->next->next;
    }

    Node* rev = reverseList(slow->next);
    Node* curr = head;

    while(rev!=NULL){
        if(curr->data!=rev->data)
            return false;
        curr = curr->next;
        rev = rev->next;
    }

    return true;
}

void displayLL(){
    Node* temp = head;
    cout<<"Linked List : ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    int size, temp;
    cout<<"Enter the number of nodes of the linked list : ";
    cin>>size;

    cout<<"Enter node 1 : ";
    cin>>temp;
    head = new Node(temp);
    Node* curr = head;

    for(int i=2;i<=size;i++){
        cout<<"Enter node "<<i<<" : ";
        cin>>temp;

        Node* tempNode = new Node(temp);
        curr->next = tempNode;
        curr = curr->next;
    }
    displayLL();

    if(isPalindrome()){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not a palindrome";
    }
}