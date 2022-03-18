// Approach:
// -> count number of nodes
// -> 'nth node from end' = (count - n)th node from beginning

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

int nthNodeFromEnd(int n){
    int count=0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }

    int ans_n = count-n;
    temp = head;

    for(int i=0;i<ans_n;i++){
        temp = temp->next;
    }
    return temp->data;
    
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
    int n;
    cout<<"\nEnter the value of n : ";
    cin>>n;
    cout<<"\nNth node from end : "<<nthNodeFromEnd(n);

}