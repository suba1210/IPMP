class Node{
public:
    Node* child[26];
    bool isEndOfWord;
    
    Node(){
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        isEndOfWord = false;
    }
    
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
    
    void insert(string& word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return (node!=NULL && node->isEndOfWord);
    }
};

bool wordBreakHelper(string A, vector<string> &B, Trie* trie){
    if(A.size()==0)
        return true;
    for(int i=1;i<=A.length();i++){
        if(trie->search(A.substr(0,i)) && wordBreakHelper(A.substr(i,A.size()-i), B, trie)){
            return true;
        }
    }
    return false;    
}


class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        if(A.size()==0)
            return true;
        
        Trie* trie = new Trie();
        
        for(auto str : B){
            trie->insert(str);
        }
        
        return wordBreakHelper(A, B, trie);
        
    }
};