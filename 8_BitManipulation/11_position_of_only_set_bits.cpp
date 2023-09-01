class Solution{
  public:
    int findPosition(int n) {
        if(n==0 || (n&(n-1))!=0){
            return -1;
        }
        return log2(n&(~(n-1)))+1;
    }
};