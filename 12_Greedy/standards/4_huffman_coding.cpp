#include<bits/stdc++.h>
using namespace std;

struct Node{
	char data;
	int freq;
	Node* left;
	Node* right;

	Node(char data, int freq, Node* left=NULL, Node* right=NULL){
		this->data=data;
		this->freq=freq;
		this->left=left;
		this->right=right;
	}
};

struct compare {

	bool operator()(Node* l, Node* r)
	{
		return (l->freq > r->freq);
	}
};

void printCodes(struct Node* root, string str){
	if(!root){
		return;
	}

	if (root->data != '$')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str+"0");
	printCodes(root->right, str+"1");

}

void huffman(char arr[], int freq[], int size){
	priority_queue<Node*, vector<Node*>, compare> pq;
	for(int i=0;i<size;i++){
		pq.push(new Node(arr[i],freq[i]));
	}

	while(pq.size()>1){
		Node* l = pq.top();
		pq.pop();

		Node* r = pq.top();
		pq.pop();

		Node* top = new Node('$',l->data+r->data,l,r);
		pq.push(top);
	}

	printCodes(pq.top(),"");
}

int main(){
	char arr[] = { 'a', 'd', 'e', 'f' };
	int freq[] = { 30, 40, 80, 60 };
	int size = sizeof(arr) / sizeof(arr[0]);

	huffman(arr, freq, size);

}