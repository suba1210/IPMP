struct Node
{
    vector<Node*> links;
    bool flag;
    string word;
    int countEnds;
    Node(){
        links.assign(26, NULL);
        flag = false;
        countEnds = 0;
    }
    
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
        node->word = word;
        (node->countEnds)++;
    }

};

void solve(int i, int j, int row, int col, vector<vector<char>>& board, Node* curr, vector<string>& ans){
    if(board[i][j]=='$' || !curr->containKey(board[i][j]))
        return;
    curr = curr->get(board[i][j]);
    
    if(curr->countEnds>0){
        ans.push_back(curr->word);
        (curr->countEnds)--;
    }
    
    char ch = board[i][j];
    board[i][j] = '$';
    
    if(i>0)
        solve(i-1, j, row, col, board, curr, ans);
    if(i<row-1)
        solve(i+1, j, row, col, board, curr, ans);
    if(j>0)
        solve(i, j-1, row, col, board, curr, ans);
    if(j<col-1)
        solve(i, j+1, row, col, board, curr, ans);
    
    board[i][j] = ch;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(int i=0; i<words.size(); i++){
            trie.insert(words[i]);
        }
        
        int row = board.size(), col = board[0].size();
        vector<string> ans;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                solve(i, j, row, col, board, trie.root, ans);
            }
        }
        
        return ans;
    }
};