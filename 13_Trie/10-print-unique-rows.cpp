class Node{
public:
    Node* child[2];
    
    bool containsKey(int key){
        return child[key]!=NULL;
    }
    
    void put(int key, Node* node){
        child[key] = node;
    }
    
    Node* get(int key){
        return child[key];
    }
};

class Trie{
public:
    Node* root;
    
    Trie(){
        root = new Node();
    }
    
    void insert(int M[MAX][MAX],int row, int totalCol, vector<vector<int>>& result){
        Node* node = root;
        bool flag = false;
        for(int i=0;i<totalCol;i++){
            if(!node->containsKey(M[row][i])){
                node->put(M[row][i], new Node());
                flag = true;
            }
            node = node->get(M[row][i]);
        }
        if(flag){
            vector<int> temp;
            for(int i=0; i<totalCol; i++){
                temp.push_back(M[row][i]);
            }
            result.push_back(temp);
        }
    }
};


vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    Trie trie;
    vector<vector<int>> result;
    
    for(int i=0;i<row;i++){
        trie.insert(M, i, col, result);
    }
    
    return result;
}