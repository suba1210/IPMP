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

Node* sortll(Node* head){
    
    int count[] = {0,0,0};

    Node* temp = head;

    // count the number of 0s, 1s, 2s 
    while(temp!=NULL){
        if(temp->data==0)
            count[0]++;
        else if(temp->data==1)
            count[1]++;
        else
            count[2]++;
        temp = temp->next;
    }
    
    temp = head;
    int i=0;

    // assign it to the linked list
    while(temp!=NULL){
        if(count[i]==0)
            i++;
        else{
            temp->data = i;
            count[i]--;
            temp = temp->next;
        }
    }

    return head;

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

    Node* ans = sortll(head);
    displayLL(ans);
    
}