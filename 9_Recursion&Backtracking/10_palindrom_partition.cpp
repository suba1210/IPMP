class Solution {
public:
  bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
  void func(string s, vector<vector<string>>& result, vector<string> path, int index){
      if(index == s.length()){
          result.push_back(path);
          return;
      }
      for(int i=index;i<s.length();i++){
          if(isPalindrome(s, index, i)){
              path.push_back(s.substr(index, i-index+1));
              func(s,result,path,i+1);
              path.pop_back();
          }
      }
  }
  vector<vector<string>> partition(string s) {
      vector<vector<string>> result;
      vector<string> path;
      func(s, result, path, 0);
      return result;
  }
};