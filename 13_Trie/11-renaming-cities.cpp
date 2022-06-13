class Node1{
public:
    Node1* child[26];
    int wordsEndWith;
    
    Node1(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        wordsEndWith = 0;
    }
    
    bool containsKey(char ch){
        return child[ch - 'a'];
    }
    
    void put(char ch, Node1* node){
        child[ch-'a'] = node;
    }
    
    Node1* get(char ch){
        return child[ch-'a'];
    }
};

class Trie{
public:
    Node1* root;
    Trie(){
        root = new Node1();
    }
    
    void insert(string word){
        Node1* node = root;
        bool flag = false;
        string str = "";
        
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node1());
                if(!flag){
                    str += word[i];
                    flag = true;
                }
            } else {
                str += word[i];
            }
            node = node->get(word[i]);
        }
        
        (node->wordsEndWith)++;
        
        if(str.length() == word.length() && node->wordsEndWith!=1){
            str += " " + to_string(node->wordsEndWith);
        }
        
        cout<<str<<'\n';
    }

};


class Solution
{
    public:
    void check(string *arr, int n){
        Trie trie;
        for(int i=0;i<n;i++){
            trie.insert(arr[i]);
        }
    }

};