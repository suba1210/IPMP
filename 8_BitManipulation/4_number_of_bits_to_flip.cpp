class Solution{
    public:
    int countSetBits(int n){
        int count = 0;
        while(n>0){
            n = n&(n-1);
            count++;
        }
        return count;
    }
    int countBitsFlip(int a, int b){
        return countSetBits(a^b);
    }
};