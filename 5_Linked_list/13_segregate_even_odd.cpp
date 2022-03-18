// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

class Solution{
public:
    Node* divide(int N, Node *head){
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        
        Node* curr = head;
        
        while(curr!=NULL){
            if((curr->data%2)==0){
                if(evenStart==NULL){
                    evenStart=curr;
                    evenEnd=evenStart;
                }
                else{
                    evenEnd->next=curr;
                    evenEnd=evenEnd->next;
                }
            }
            else{
                if(oddStart==NULL){
                    oddStart=curr;
                    oddEnd=oddStart;
                }
                else{
                    oddEnd->next=curr;
                    oddEnd=oddEnd->next;
                }
            }
            curr=curr->next;
        }
        
        if(oddStart==NULL || evenStart==NULL){
            return head;
        }
        
        evenEnd->next=oddStart;
        oddEnd->next=NULL;
        
        head = evenStart;
        
        return evenStart;
        
        
    }
};



int main() {
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
