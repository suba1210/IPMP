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

    void preorderTraversal(vector<string>& arr, Node* node, vector<vector<string>>& result){
        if(node==NULL){
            return;
        }
        for(int i=0;i<26;i++){
            if(node->child[i]!=NULL){
                vector<string> temp;
                for(int j=0;j<(node->child[i]->indices).size();j++){
                    temp.push_back(arr[node->child[i]->indices[j]]);
                }
                if(temp.size()!=0)
                    result.push_back(temp);
                preorderTraversal(arr, node->child[i], result);
            }
        }
    }

};


class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        Trie trie;
        
        for(int i=0;i<string_list.size();i++){
            string str = string_list[i];
            sort(str.begin(), str.end());
            trie.insert(str, i);
        }
    
        vector<vector<string> > result;
        trie.preorderTraversal(string_list, trie.root, result);
        
        return result;
    }
};