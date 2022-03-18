#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void displayLL(Node* head){
    Node* temp = head;
    cout<<"Linked List : ";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void splitll(Node** a, Node** b, Node* source){

    Node* slow = source;
    Node* fast = source->next;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    *a = source;
    *b = slow->next;
    slow->next = NULL;

}

Node* sortedMerge(Node* a, Node* b){
    Node* result = NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    
    if(a->data <= b->data){
        result = a;
        result->next = sortedMerge(a->next,b);
    }else{
        result = b;
        result->next = sortedMerge(a,b->next);
    }
    return result;
}

void mergeSort(Node** head){
    Node* a;
    Node* b;
    Node* headRef = *head;

    if((headRef==NULL) || (headRef->next==NULL)){
        return;
    }

    splitll(&a,&b,headRef);

    mergeSort(&a);

    mergeSort(&b);

    *head = sortedMerge(a,b);
}

int main(){
    int size, temp;
    Node* head;
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

    
    mergeSort(&head);
    displayLL(head);

}