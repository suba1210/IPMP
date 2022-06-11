class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet, addedSet;
        for(auto x : wordList){
            wordSet.insert(x);
        }
        if(wordSet.find(endWord)==wordSet.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        addedSet.insert(beginWord);
        int changes = 1;
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                string str = q.front();
                q.pop();
                if(str==endWord)
                    return changes;
                
                for(int i=0;i<str.length();i++){
                    for(char c = 'a';c<='z';c++){
                        string temp = str;
                        temp[i] = c;
                        if(wordSet.find(temp)!=wordSet.end() && addedSet.find(temp)==addedSet.end()){
                            q.push(temp);
                            addedSet.insert(temp);
                        }
                    }
                }
            }
            changes++;
        }
        return 0;
    }
};