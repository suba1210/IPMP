#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x){
        this->data = x;
        this->prev = NULL;
        this->next = NULL;
    }
};

class Stack{
public:
    
    Node* head;
    Node* mid;
    int size;

    Stack(){
        this->size = 0;
    }

    void push(int x){
        size++;
        Node* temp = new Node(x);
        if(size==1){        
            head = temp;
            mid = temp;
            return;
        }
        head->prev = temp;
        temp->next = head;
        head = temp;
        if(size%2==1){
            mid = mid->prev;
        }       
    }

    void pop(){
        size--;
        if(size==1){
            head = NULL;
            mid = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        if(size%2==0){
            mid = mid->next;
        }
        
    }
    
    int getMin(){
        return mid->data;
    }
    
    void deleteMin(){
        if(size==1){
            head=NULL;
            mid=NULL;
        }
        Node* temp = mid;
        if(size%2==0){
            mid->prev->next = mid->next;
            mid->next->prev = mid->prev;
            mid = mid->prev;
        }
        mid->next->prev = mid->prev;
        mid->prev->next = mid->next;
        mid = mid->next;
        
        size--;
        temp=NULL;
        free(temp);
    }

};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.pop();
    s.pop();
    
    cout<<s.getMin()<<endl;
    
    s.deleteMin();
    
    Node* temp = s.head;
    
    cout<<s.getMin()<<endl;

    while(temp!=NULL){
        cout<<temp->data;
        temp = temp->next;
    }

}
