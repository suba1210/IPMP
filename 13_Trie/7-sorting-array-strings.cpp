#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    vector<int> indices;
    Node* child[26];

    bool containsKey(char ch){
        return child[ch-'a']!=NULL;
    }

    void put(char ch, Node* node){
        child[ch-'a'] = node;
    }

    Node* get(char ch){
        return child[ch-'a'];
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(string& word, int index){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        (node->indices).push_back(index);
    }

    void preorderTraversal(string arr[], Node* node){
        if(node==NULL){
            return;
        }
        for(int i=0;i<26;i++){
            if(node->child[i]!=NULL){
                for(int j=0;j<(node->child[i]->indices).size();j++){
                    cout<<arr[node->child[i]->indices[j]]<<" ";
                }
                preorderTraversal(arr, node->child[i]);
            }
        }
    }

};

void printSorted(string arr[], int n)
{
    Trie trie;

    for(int i=0;i<n;i++){
        trie.insert(arr[i], i);
    }

    trie.preorderTraversal(arr, trie.root);
}

int main()
{
	string arr[] = { "abc", "xyz", "abcd", "bcd", "abc" };
	int n = sizeof(arr) / sizeof(arr[0]);
	printSorted(arr, n);
	return 0;
}
