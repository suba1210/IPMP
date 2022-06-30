struct Node{
    vector<Node*> children;
    bool isEnd;
    Node(){
        children.assign(26, NULL);
        isEnd = false;
    }
    
    bool containsKey(char ch){
        return children[ch - 'a']!=NULL;
    }
    
    void put(char ch, Node* node){
        children[ch - 'a'] = node;
    }
    
    Node* get(char ch){
        return children[ch - 'a'];
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    
    bool insertAndCheck(string word){
        Node* node = root;
        for(int i=0; i<word.length()-1; i++){
            if(node->containsKey(word[i]) && node->isEnd){
                node = node->get(word[i]);
            } else {
                return false;
            }
        }
        node->put(word[word.length()-1], new Node());
        node->isEnd = true;
        return true;
    }
      
};

string completeString(int n, vector<string> &a){
    sort(a.begin(), a.end(), [](string x, string y){return x.length() < y.length();});
    string longest = "";
    Trie obj;
    for(string word : a){
        if(obj.insertAndCheck(word)){
            if(word.length() > longest.length()){
                longest = word;
            } else if(word.length() == longest.length() && word < longest){
                longest = word;
            }
        }
    }
    
    return (longest == "" ? "None" : longest);
}